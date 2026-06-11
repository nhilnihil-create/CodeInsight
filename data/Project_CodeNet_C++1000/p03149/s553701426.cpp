#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using vs = vector<string>;
const int MOD = 1000000007;

int main(){
    string s;
    char c;
    rep(i,4){
        cin>>c;
        s += c;
    }
    sort(all(s));
    puts(s=="1479"?"YES":"NO");
    
    return 0;
}