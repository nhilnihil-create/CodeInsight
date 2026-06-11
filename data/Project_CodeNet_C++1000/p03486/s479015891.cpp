#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s,t;cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    rep(i,s.size()){
        if(s[i]-'0'<t[i]-'0'){
            cout<<"Yes"<<endl;
            return 0;
        }else if(s[i]-'0'>t[i]-'0'){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(s.size()<t.size()){
        cout<<"Yes"<<endl;
        return 0;
    }else if(s.size()>t.size()){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}
