#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> g(s.length());
    rep(i,s.length())g[i]=0;
    rep(i,s.length()){
        if(i)g[i]=g[i-1];
        if(s[i]=='A'&&s[i+1]=='C'){
            g[i+1]=g[i]+1;
            i++;
            //continue;
        }
    }
    rep(i,q){
        int l,r;
        cin >> l >> r;
        cout << g[r-1]-g[l-1]<<endl;
    }
    
    return 0;
}
