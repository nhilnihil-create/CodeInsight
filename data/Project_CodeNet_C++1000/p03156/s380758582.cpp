#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    int n;
    int a,b;
    cin >> n >> a >> b;
    int c1 = 0,c2 = 0,c3 = 0;
    rep(i,n){
        int x;
        cin >> x;
        if(x <= a) c1++;
        else if(x > a && x <= b) c2++;
        else c3++;
    }
    cout << min({c1,c2,c3}) << endl;
    return 0;
}