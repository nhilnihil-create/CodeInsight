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
#include <math.h>
#include <iomanip>
using namespace std;
#define int long long

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;

    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }

    int n = s.size();
    vector<bool> tukatta(26);
    for(int i = 0;i < n;i ++){
        tukatta.at(s.at(i)-'a') = true;
    }

    if(n < 26){
        int x = 0;
        for(;;x ++){
            if(tukatta.at(x) == false) break;
        }

        char t = 'a' + x;
        cout << s + t << endl;
        return 0;
    }

    vector<bool> tukatta2(26,false);
    tukatta2.at(s.at(25) - 'a') = true;

    for(int i = 24;i >= 0;i --){
        tukatta2.at(s.at(i) - 'a') = true;
        s.pop_back();
        for(int j = s.at(i) - 'a' + 1;j < 26;j ++){
            if(tukatta2.at(j) == true){
                s.pop_back();
                s.push_back('a' + j);

                cout << s << endl;
                return 0;

            }
        }
    }
}