#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

const int INF = 1e9;

int n, cc;

int main() {
    cin >> n >> cc;
    vector< vector<int> > Dmap(cc, vector<int>(cc, 0));
    vector< vector<int> > cmap(n, vector<int>(n, 0));
    vector< vector<int> > ccnt(3, vector<int>(cc, 0));
    for(int i = 0; i < cc; ++i) {
        for(int j = 0; j < cc; ++j) {
            cin >> Dmap.at(i).at(j);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> cmap.at(i).at(j);
            cmap.at(i).at(j)--;
            int ch = (i+j)%3;
            ccnt.at(ch).at(cmap.at(i).at(j))++;
        }
    }

    /*cout << "ccnt" << endl;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < cc; ++j) {
            cout << ccnt.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    int ans = INF;
    for(int i = 0; i < cc; ++i) {
        for(int j = 0; j < cc; ++j) {
            if(j != i) {
                for(int k = 0; k < cc; ++k) {
                    if(k != i && k != j) {
                        int sum = 0;
                        // cout << i << " " << j << " " << k << endl;
                        for(int l = 0; l < cc; ++l) {
                            if(l != i) {
                                sum += ccnt.at(0).at(l)*Dmap.at(l).at(i);
                            }
                        }
                        for(int l = 0; l < cc; ++l) {
                            if(l != j) {
                                sum += ccnt.at(1).at(l)*Dmap.at(l).at(j);
                            }
                        }
                        for(int l = 0; l < cc; ++l) {
                            if(l != k) {
                                sum += ccnt.at(2).at(l)*Dmap.at(l).at(k);
                            }
                        }
                        // cout << sum << endl;
                        chmin(ans, sum);
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
}