#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long x[n+1],y[n+1],t[n+1];
    x[0]=0;
    y[0]=0;
    t[0]=0;
    bool f=true;
    f(i,1,n+1){
        cin>>t[i]>>x[i]>>y[i];
    }
    f(i,1,n+1){
        if(t[i]-t[i-1]<abs(x[i]-x[i-1])+abs(y[i]-y[i-1])){
            f=false;
            break;
        }
        else if((t[i]-t[i-1]-abs(x[i]-x[i-1])-abs(y[i]-y[i-1]))%2!=0){
            f=false;
            break;
        }
    }
    if(f){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
