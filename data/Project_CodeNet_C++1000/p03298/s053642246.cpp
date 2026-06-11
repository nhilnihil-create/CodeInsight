#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define INF 1000000000

int main(){
    int n;
    string s;
    cin>>n>>s;
    map<pair<string,string>,ll> ms;
    rep(i,1<<n){
        int ii=i;
        string s0,s1;
        rep(j,n){
            if(ii&1) s0+=s[j];
            else s1+=s[j];
            ii>>=1;
        }
        reverse(s1.begin(),s1.end());
        ms[make_pair(s0,s1)]++;
    }
    ll ans=0;
    rep(i,1<<n){
        int ii=i;
        string s0,s1;
        rep(j,n){
            if(ii&1) s0+=s[j+n];
            else s1+=s[j+n];
            ii>>=1;
        }
        reverse(s1.begin(),s1.end());
        if(ms.count(make_pair(s1,s0))){
            ans+=ms[make_pair(s1,s0)];
        }
    }
    cout<<ans<<endl;
    return 0;
}
