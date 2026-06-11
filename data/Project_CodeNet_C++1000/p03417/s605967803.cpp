#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int n,m,ans;cin>>n>>m;
    
    if(n==1 || m==1)ans = abs(n*m-2);
    else if(n==2 || m==2)ans=0;
    else ans = (n-2)*(m-2);

    cout<<ans<<endl;
}