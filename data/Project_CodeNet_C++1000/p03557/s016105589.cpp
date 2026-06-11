#include <bits/stdc++.h>
using namespace std;

int u_b(vector<int> &a, int x){
    int left=-1,right=a.size();
    while(right-left>1){
        int mid=(left+right)/2;
        if(a[mid]>x) right=mid;
        else left=mid;
    }
    return right;
}

int main(){
    int n; cin>>n;
    vector<int> a(n),b(n),c(n);
    for(int &x: a) cin>>x;
    for(int &x: b) cin>>x;
    for(int &x: c) cin>>x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    vector<long long> mem(n+1,0);
    for(int i=0;i<n;i++){
        mem[i+1]=mem[i]+n-u_b(c,b[i]);
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=mem[n]-mem[u_b(b,a[i])];
    }
    cout<<ans<<endl;
}