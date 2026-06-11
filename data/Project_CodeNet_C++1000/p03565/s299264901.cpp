#include <bits/stdc++.h>
#include <string>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second　//pairの二つ目の要素


int main(){
    string s,t, ans;
    cin>>s>>t;
    bool b;
//    rep(i,s.size()-t.size()+1){
    for(int i=s.size()-t.size();i>=0;i--){
        ans=s;
        b=true;
        rep(j,t.size()){
            if(s[j+i]=='?'){
                ans[j+i]=t[j];
                continue;
            }
            b=b&&(s[j+i]==t[j]);
//            cout<<i<<" "<<s[j+i]<<" "<<t[j]<<endl;
            if(!b) break;
        }
        if(b)break;
    }
    if(b){
        rep(i,s.size()) if(ans[i]=='?') ans[i]='a';
        cout<<ans<<endl;
    }
    else cout<<"UNRESTORABLE"<<endl;
    return 0;
}