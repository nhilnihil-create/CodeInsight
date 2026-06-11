#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int h,w,n,sr,sc;
string s,t;
int main(){
    cin>>h>>w>>n>>sr>>sc;
    cin>>s>>t;
    int y,x;
    y=sr;
    rep(i,n){
        if(s[i]=='D') ++y;
        if(y>h){
            cout<<"NO"<<endl;
            return 0;
        }
        if(t[i]=='U'&&y>1) --y;
    }
    y=sr;
    rep(i,n){
        if(s[i]=='U') --y;
        if(y<1){
            cout<<"NO"<<endl;
            return 0;
        }
        if(t[i]=='D'&&y<h) ++y;
    }
    x=sc;
    rep(i,n){
        if(s[i]=='R') ++x;
        if(x>w){
            cout<<"NO"<<endl;
            return 0;
        }
        if(t[i]=='L'&&x>1) --x;
    }
    x=sc;
    rep(i,n){
        if(s[i]=='L') --x;
        if(x<1){
            cout<<"NO"<<endl;
            return 0;
        }
        if(t[i]=='R'&&x<w) ++x;
    }
    cout<<"YES"<<endl;
    return 0;
}
