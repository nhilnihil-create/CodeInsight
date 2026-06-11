#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N,C;
    cin >> N >> C;
    vector<vector<int>> D(C,vector<int>(C));
    for(int i = 0;i < C;i++) {
        for(int j = 0;j < C;j++) {
            cin >> D.at(i).at(j);
        }
    }
    vector<vector<int>> G(N,vector<int>(N));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            int A;
            cin >> A;
            A--;
            G.at(i).at(j) = A;
        }
    }
    vector<vector<int>> color(3,vector<int>(C));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            color.at((i + j) % 3).at(G.at(i).at(j))++;
        }
    }
    ll ret = INF;
    for(int i = 0;i < C;i++) {
        for(int j = 0;j < C;j++) {
            for(int k = 0;k < C;k++) {
                if(i != j && j != k && i != k) {
                    ll count = 0;
                    for(int l = 0;l < C;l++) {
                        count += color.at(0).at(l) * D.at(l).at(i);
                    }
                    for(int l = 0;l < C;l++) {
                        count += color.at(1).at(l) * D.at(l).at(j);
                    }
                    for(int l = 0;l < C;l++) {
                        count += color.at(2).at(l) * D.at(l).at(k);
                    }
                    ret = min(ret,count);
                }
            }
        }
    }
    cout << ret << endl;
}