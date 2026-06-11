#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int64_t> a(n);
    for(int i=0;i<n;i++){
        int64_t x;
        cin>>x;
        a[i]=x-i;
    }
    sort(a.begin(),a.end());

    
    // for(auto &p:a) cout<<p<<endl;


    int j=(n-1)/2;
    int64_t sum=0;
    for(int i=0;i<n;i++){
        sum+=abs(a[i]-a[j]);
    }
    cout<<sum;
}