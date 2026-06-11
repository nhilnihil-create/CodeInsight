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
    cin >> n;
    int cnt = 0;
    int a = 0, b = 0, ab = 0;
    string s[n];
    rep(i,n) cin >> s[i];
    rep(i,n){
        rep(j,int(s[i].size()-1)){
            if(s[i][j] == 'A' && s[i][j+1] == 'B') cnt++;
        }
        if(s[i][0] == 'B' && s[i][int(s[i].size())-1]  == 'A') ab++;
        else if(s[i][0] == 'B') b++;
        else if(s[i][int(s[i].size())-1] == 'A') a++;
    }
    // cout << a << " " << b << endl;
    // cout << cnt << endl;
    if(a == b && a == 0){
        cout << cnt + max(ab - 1,0) << endl;
    }else if(a == b && a != 0){
        cout << cnt + ab + min(a,b) << endl;
    }else if(a > b){
        cout << cnt + ab + min(a,b) << endl;
    }else{
        cout << cnt + ab + min(a,b) << endl;
    }
    return 0;
}