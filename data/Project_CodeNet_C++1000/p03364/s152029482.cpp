#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,int> P;

int main() {
    int N;
    cin >> N;
    vector<vector<char>> vec(N,vector<char>(N));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            cin >> vec.at(i).at(j);
        }
    }
    int ret = 0;
    for(int i = 0;i < N;i++) {
        bool ret1 = true;
        for(int j = 0;j < N;j++) {
            for(int k = 0;k < N;k++) {
                int A,B;
                if(k + i >= N) {
                    A = k + i - N;
                }
                else {
                    A = k + i;
                }
                if(j - i < 0) {
                    B = j - i + N;
                }
                else {
                    B = j - i;
                }
                if(vec.at(j).at(k) != vec.at(A).at(B)) {
                    ret1 = false;
                }
            }
        }
        bool ret2 = true;
        for(int j = 0;j < N;j++) {
            for(int k = 0;k < N;k++) {
                int A,B;
                if(k - i < 0) {
                    A = k - i + N;
                }
                else {
                    A = k - i;
                }
                if(j + i >= N) {
                    B = j + i - N;
                }
                else {
                    B = j + i;
                }
                if(vec.at(j).at(k) != vec.at(A).at(B)) {
                    ret2 = false;
                }
            }
        }
        if(i == 0 && ret1 == true) {
            ret += N;
        }
        if(i != 0 && ret1 == true) {
            ret += N - i;
        }
        if(i != 0 && ret2 == true) {
            ret += N - i;
        }
    }
    cout << ret << endl;
}