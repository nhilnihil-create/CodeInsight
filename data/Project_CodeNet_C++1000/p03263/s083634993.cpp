#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b + 1; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

int main()
{
    int h,w;
    cin >> h >> w;
    vector<vector<int>> v(h,vector<int>(w));
    REP(i,h){
        REP(j,w){
            cin >> v[i][j];
        }
    }
    queue<pair<int,int>> q1;
    queue<pair<int,int>> q2;
    int n=0;
    REP(i,h){
        REP(j,w){
            if(v[i][j]%2==1){
                v[i][j]--;
                q1.push(make_pair(i+1,j+1));
                if(j+1==w){
                    if(i+1==h){
                        continue;
                    }
                    v[i+1][j]++;
                    q2.push(make_pair(i + 2, j + 1));
                }
                else{
                    v[i][j+1]++;
                    q2.push(make_pair(i + 1, j + 2));
                }
                n++;
            }
        }
    }
    cout << n << endl;
    REP(i,n){
        cout << q1.front().first << " " << q1.front().second << " ";
        cout << q2.front().first << " " << q2.front().second << endl;
        q1.pop();
        q2.pop();
    }
}
