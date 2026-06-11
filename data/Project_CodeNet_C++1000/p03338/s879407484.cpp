#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;string s;cin>>s;
    int res=0;
    rep(i,s.size()){
        int buf=0;
        string x=s.substr(0,i+1),y=s.substr(i+1,s.size()-i);
        map<char,int> mp1,mp2;
        rep(j,x.size())mp1[x[j]]++;
        rep(j,y.size())mp2[y[j]]++;
        for(auto& p:mp1){
            if(mp2[p.first]!=0)buf++;
        }
        chmax(res,buf);
    }
    cout<<res<<endl;
}