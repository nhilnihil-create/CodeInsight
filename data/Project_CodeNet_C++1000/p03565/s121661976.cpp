#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> lP;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    string s,t;
    cin>>s>>t;

    int ssize=s.size();
    int tsize=t.size();
    bool judge=true;
    if(ssize<tsize) judge=false;
    else{
    for(int i=ssize-1;i>=tsize-1;i--){
        judge=true;
        string v=s;
        per(j,tsize){
            if(v[i-j]==t[tsize-j-1]) continue;
            else if(v[i-j]=='?'){
                v[i-j]=t[tsize-j-1];
            }
            else judge=false;

        }
        if(judge){
            s=v;
            break;
        }
    }
    }
    if(!judge) cout<<"UNRESTORABLE"<<endl;
    else{
        rep(i,ssize){
        if(s[i]=='?') s[i]='a';
    }

    cout<<s<<endl;
    }

}
