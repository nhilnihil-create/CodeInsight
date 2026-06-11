#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    long long sum=0;
    map<long long,long long>m;
    m[0]++;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        m[sum]++;
    }
    long long ans=0;
    for(auto itr=m.begin();itr!=m.end();itr++){
        long long x=itr->second;
        ans+=x*(x-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}