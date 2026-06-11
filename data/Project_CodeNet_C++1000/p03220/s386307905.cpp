#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,t,a,maxi=1;
    cin>>n;
    cin>>t>>a;
    float h[n];
    f(i,0,n){
        cin>>h[i];
        h[i]=t-h[i]*0.006;
    }
    f(i,1,n){
        if(abs(a-h[i])<abs(a-h[maxi-1])){
            maxi=i+1;
        }
    }
    cout<<maxi<<endl;
    return 0;
}
