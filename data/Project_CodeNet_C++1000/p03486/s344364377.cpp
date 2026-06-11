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
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    int x=min(s.size(),t.size());
    rep(i,x){
        if(s[i]<t[i]){
            cout<<"Yes"<<endl;
            return 0;
        }else if(s[i]>t[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(s.size()<t.size())cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}