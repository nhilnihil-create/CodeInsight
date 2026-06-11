#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    vector<vector<int>> cnt(N,vector<int>(22));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < 22;j++) {
            cnt.at(i).at(j) = vec.at(i) % 2;
            vec.at(i) /= 2;
        }
    }
    ll ret = 0;
    int right = 0;
    vector<int> count(22);
    for(int left = 0;left < N;left++) {
        bool ret2 = true;
        while(right < N && ret2 == true) {
            for(int i = 0;i < 22;i++) {
                if(cnt.at(right).at(i) == 1) {
                    if(count.at(i) == 1) {
                        ret2 = false;
                    }
                    count.at(i)++;
                }
            }
            if(ret2 == false) {
                break;
            }
            right++;
        }
        ret += (right - left);
        for(int i = 0;i < 22;i++) {
            if(right != N) {
                count.at(i) -= cnt.at(right).at(i);
            }
            count.at(i) -= cnt.at(left).at(i);
        }
        if(right == left) {
            right++;
        }
    }
    cout << ret << endl;
}