#include <iostream>
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

int main(){
    lli n,m,ans;
//    lli i,j,k;
    cin>>n>>m;
    if((n>1)&&(m>1)){
        ans=(n-2)*(m-2);
    }
    else{
        if(n==1){
            if(m==1){
                ans=1;
            }
            else{
                ans=m-2;
            }
        }
        else{
            ans=n-2;
        }
    }
    cout<<ans<<endl;
}
