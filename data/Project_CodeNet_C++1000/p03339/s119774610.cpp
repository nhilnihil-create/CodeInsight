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
int main(){
    cout << fixed << setprecision(10);
    int n;
    string s;
    cin >> n >> s;
    vector<int> left(n+1,0), right(n+1,0);
    int ans = inf;
    int same = 0;
    rep(i,n){
        if(i == 0){
            if(s[i] == 'E') left[i+1]++;
        }else if(i != n-1){
            if(s[i] == 'E') left[i+1] = left[i] + 1;
            else left[i+1] = left[i];
        }
    }
    for(int i = n-1;i >= 0; i--){
        if(i == n-1){
            if(s[i] == 'W') right[i-1]++;
        }else if( i != 0){
            if(s[i] == 'W') right[i-1] = right[i] + 1;
            else right[i-1] = right[i];
        }
    }
    rep(i,n){
        int now = left[i] + right[i];
        if(now > same){
            same = now;
            ans = n - 1 - same;
        }
    }
    cout << ans << endl;
    return 0;
}