#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long x;
    cin>>x;
    vector<long long> a(x+1,0);
    a[1]=1;
    for(long long i=2;i*i<=x;i++){
        long long v=i*i;
        while(v<=x){
            a[v]=1;
            v*=i;
        }
    }
    for(int i=x;i>=1;i--){
        if(a[i]==1){
            cout<<i<<endl;
            return 0;
        }
    }
}
