#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;
string s;

int main(){
    cin>>n>>s;
    int ans=0;
    for(int i=1;i<n-1;i++){
        string left=s.substr(0,i);
        string right=s.substr(i,n-i);
        int cnt=0;
        rep(j,26){
            if(left.find(char('a'+j))!=string::npos && 
            right.find(char('a'+j))!=string::npos) cnt++;
        }
        chmax(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}