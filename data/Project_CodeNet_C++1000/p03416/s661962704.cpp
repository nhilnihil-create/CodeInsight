#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long a,b,ans=0;
    cin>>a>>b;
    f(i,a,b+1){
        if(i/10000==i%10&&(i/1000)%10==(i%100)/10){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
