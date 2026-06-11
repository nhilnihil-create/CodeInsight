#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,m,maxl=1,minr=100000;
    cin>>n>>m;
    long long l[m],r[m];
    f(i,0,m){
        cin>>l[i]>>r[i];
        if(l[i]>maxl){
            maxl=l[i];
        }
        if(r[i]<minr){
            minr=r[i];
        }
    }
    if(minr>=maxl){
        cout<<minr-maxl+1<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}
