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
    lli k,a,b,ans;
    cin>>k>>a>>b;
    if((b-a<=2)||(k<a)){
        ans=k+1;
    }
    else{
        k=k-a+1;
        lli def=b-a;
        ans=a;
        ans+=def*(k/2);
        if(k%2==1){
            ans++;
        }
    }
    cout<<ans<<endl;
}
