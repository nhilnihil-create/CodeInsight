#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    for(long long i=0;i<n;i++){
        v[i]=v[i]-i-1;
    }
    sort(v.begin(),v.end());
    long long a=v[n/2];
    long long ans=0;
    for (int i = 0; i < n; i++){
		ans = ans + abs(v[i] - a);
    }
        cout<<ans;

}