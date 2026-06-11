#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long a,b,c,x,ans=0;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>x;
    f(i,0,a+1){
        f(j,0,b+1){
            f(k,0,c+1){
                if(i*500+j*100+k*50==x){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
