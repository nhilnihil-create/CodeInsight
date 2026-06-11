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
    rep(i,s.size()){
        string ns="";
        ns.push_back(s[s.size()-1]);
        ns+=s.substr(0,s.size()-1);
        if(ns==t){
            cout<<"Yes"<<endl;
            return 0;
        }
        //cout<<ns<<endl;
        s=ns;
    }
    cout<<"No"<<endl;
}