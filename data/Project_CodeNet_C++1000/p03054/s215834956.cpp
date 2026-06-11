#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(n,v) cout<<#v<<":";for(int i=0;i<n;i++)cout<<v[i]<<" ";cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    ll h,w,n;
    cin>>h>>w>>n;
    ll si,sj;
    cin>>si>>sj;
    string S,T;
    cin>>S>>T;
    //right
    ll pos=sj;
    for(int i=0;i<S.size();i++){
        if(S[i]=='R') pos++;
        if(pos>w){
            cout<<"NO"<<endl;
            return 0;
        }
        if(T[i]=='L'&&pos>1) pos--;
    }
    //left
    pos=sj;
    for(int i=0;i<S.size();i++){
        if(S[i]=='L') pos--;
        if(pos<1){
            cout<<"NO"<<endl;
            return 0;
        }
        if(T[i]=='R'&&pos<w) pos++;
    }
    //up
    pos=si;
    for(int i=0;i<S.size();i++){
        if(S[i]=='U') pos--;
        if(pos<1){
            cout<<"NO"<<endl;
            return 0;
        }
        if(T[i]=='D'&&pos<h) pos++;
    }
    //down
    pos=si;
    for(int i=0;i<S.size();i++){
        if(S[i]=='D') pos++;
        if(pos>h){
            cout<<"NO"<<endl;
            return 0;
        }
        if(T[i]=='U'&&pos>1) pos--;
    }
    cout<<"YES"<<endl;
    return 0;
}
