#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,m,k,aa,ans=0;
    cin>>n>>m;
    vector<long long> a(m,0) ;
    f(i,0,n){
        cin>>k;
        f(j,0,k){
            cin>>aa;
            a[aa-1]++;
        }
    }
    f(i,0,m){
        if(a[i]==n){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
