#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s,t;cin>>s>>t;
    for(int i=(s.size()-t.size());i>=0;i--){
        string ps=s.substr(i,t.size());
        //cout<<ps<<endl;
        bool jud=true;
        rep(j,t.size())if(ps[j]!=t[j]&&ps[j]!='?'){
            jud=false;break;
        }
        if(jud){
            rep(j,t.size())s[i+j]=t[j];
            rep(j,s.size())if(s[j]=='?')s[j]='a';
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<"UNRESTORABLE"<<endl;
}