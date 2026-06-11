#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main(){
    int n,m;
    cin>>n>>m;
    int ans;
    if(n==1&m==1){
        ans=1;
    }else{
        ans=abs((n-2)*(m-2));
    }
    cout<<ans<<endl;
    return 0;
}