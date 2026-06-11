#include <bits/stdc++.h>
using namespace std;

int main() {
    long n,k;cin>>n>>k;
//    long c = 200000;
    long a[n];
    
    for(long i=0;i<n;++i){
        a[i] =0;
    }
    
    long tmp;
    for(long i=0;i<n;++i){
        cin>>tmp;
        a[tmp-1] +=1;
    }
    sort(a, a+n, greater<long>());
    long ans=0;
    for(long i=k;i<n;++i){
        if(a[i]==0)break;
        ans+=a[i];
    }
    cout<<ans<<endl;
	return 0;
}