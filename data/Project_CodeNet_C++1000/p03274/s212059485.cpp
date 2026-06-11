#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> x(n);
    for(int i=0;i<n;i++) cin>>x[i];

    long long ans=1e9;
    for(int i=0;i<n-k+1;i++){
        ans=min(ans,min(abs(x[i]),abs(x[i+k-1]))+abs(x[i+k-1]-x[i]));
    }
    cout<<ans<<endl;
}