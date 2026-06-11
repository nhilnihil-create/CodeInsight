#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;

int sum(vector<vector<long long>> &data, vector<int> &comp,long long G, int n){
    if (n == 0){
        int ans = 0;
        for (long long sub = 0; sub < comp.size(); sub++){
            long long sum = 0;
            int ansi = 0;
            if (comp.at(sub) == 1){
                continue;
            }
            for (long long i = 0; i < comp.size(); i++){
                if (comp.at(i) == 1) {
                    sum += (i + 1) * 100 * data.at(i).at(0) + data.at(i).at(1);
                    ansi += data.at(i).at(0);
                }
            }
            bool less = false;
            for (long long i = 0; i < data.at(sub).at(0); i++){
                if (sum < G && i == data.at(sub).at(0) - 1) {
                    less = true;
                }
                if (sum < G) {
                    sum += (sub + 1) * 100;
                    ansi++;
                }
                else {
                    break;
                }
            }
            if (less) {
                sum += data.at(sub).at(1);
            }
            if (sum < G) {
                ansi = 0;
            }
            if (ans ==  0 || ansi < ans) {
                ans = ansi;
            }
        }
        return ans;
    }
    else {
        comp.at(comp.size() - n) = 0;
        int ans0 = sum(data, comp, G, n - 1);
        comp.at(comp.size() - n) = 1;
        int ans1 = sum(data, comp, G, n - 1);
        if (ans0 == 0){
            return ans1;
        }
        else if (ans1 == 0){
            return ans0;
        }
        return min(ans0, ans1);
    }
}

int main() {
    long long D, G;
    cin >> D >> G;
    vector<vector<long long>> data(D, vector<long long>(2));
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> data.at(i).at(j);
        }
    }
    vector<int> comp(D, 0);
    int ans = sum(data, comp, G, D);
    cout << ans << endl;
}