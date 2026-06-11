#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s;cin>>s;
    string t;
    rep(i,s.size()){
        if(i<s.size()-1&&(s[i]=='B'&&s[i+1]=='C')){
            t.push_back('D');
            i++;
        }
        else t.push_back(s[i]);
    }
    //cout<<t<<endl;
    reverse(t.begin(),t.end());
    vector<ll> a(t.size(),0);
    rep(i,t.size())if(t[i]=='D')a[i]++;
    rep(i,t.size()-1)a[i+1]=(t[i+1]=='D'||t[i+1]=='A')? a[i]+a[i+1]:0;
    reverse(t.begin(),t.end());
    reverse(a.begin(),a.end());
    ll res=0;
    rep(i,t.size()-1){
        if(t[i]=='A'){
            //cout<<i<<" "<<a[i+1]<<endl;
            res+=a[i+1];
        }
    }
    cout<<res<<endl;
}
