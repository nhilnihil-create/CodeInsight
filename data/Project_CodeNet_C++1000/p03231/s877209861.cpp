#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <functional>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007

using namespace std;

lli gcd(lli a,lli b){
    lli x,y;
    x=max(a,b);
    y=min(a,b);
    if(x%y==0){
        return y;
    }
    else{
        return gcd(y,x%y);
    }
}

lli lcm(lli a,lli b){
    lli x,y;
    x=max(a,b);
    y=min(a,b);
    return x*y/gcd(x,y);
}

int main(){
    lli n,m,l,g;
    string s,t,x;
    vector<char> nvec,mvec;
    lli i=0,j,k;
    cin>>n>>m>>s>>t;
    l=lcm(n,m);
    g=gcd(n,m);
    if(g!=1){
        m/=g;
        n/=g;
        rep(i,0,s.size()/n){
            if(s[n*i]!=t[m*i]){
                l=-1;
                break;
            }
        }
    }
    else{
        if(s[0]!=t[0]){
            l=-1;
        }
    }
    cout<<l<<endl;
}
