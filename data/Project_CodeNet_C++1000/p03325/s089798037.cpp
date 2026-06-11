#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,ans=0;
    cin>>n;
    vector<long long> a(n);
    for(long long i=0;i<n;i++){
        cin>>a[i];
        while(a[i]%2==0){
            ans++;
            a[i]/=2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
