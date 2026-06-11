#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

string s;

int main(){
    cin>>s;
    int l=s.size();
    int n=l-7;
    bool flag=false;
    if(n==0) flag=true;
    else{
        string sf=s.substr(0,l-n);
        string se=s.substr(n,l-n);
        if(sf=="keyence") flag=true;
        else if(se=="keyence") flag=true;
        else{
            rep(i,0,l-n){
                string sss=s.substr(0,i)+s.substr(i+n,7-i);
                if(sss=="keyence") flag=true;
            }
        }
    }
    if(flag) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    return 0;
}