#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long a,b,c,k,ans;
    cin>>a>>b>>c>>k;
    if(k%2==0){
        ans=a-b;
    }
    else{
        ans=b-a;
    }
    cout<<ans<<endl;
    return 0;
}
