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

//lli gcd(lli a,lli b){
//    lli x,y;
//    x=max(a,b);
//    y=min(a,b);
//    if(x%y==0){
//        return y;
//    }
//    else{
//        return gcd(y,x%y);
//    }
//}
//
//lli lcm(lli a,lli b){
//    lli x,y;
//    x=max(a,b);
//    y=min(a,b);
//    return x*y/gcd(x,y);
//}

int main(){
    lli n,ans=1;
    string s;
    map<char,lli> map;
    lli i,j;
    cin>>n>>s;
    rep(i,0,n){
        map[s[i]]++;
    }
    for(auto itr=map.begin();itr!=map.end();itr++){
        ans*=itr->second+1;
        ans%=N;
    }
    ans--;
    cout<<ans<<endl;
}
