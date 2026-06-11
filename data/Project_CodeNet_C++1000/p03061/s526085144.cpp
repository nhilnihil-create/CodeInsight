#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int gcd(int x,int y){ return y ? gcd(y,x%y) : x;}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    vector<int> l(n),r(n);
    for(int i=0;i<n-1;i++) l[i+1]=gcd(l[i],a[i]);
    for(int i=n-1;i>=1;i--) r[i-1]=gcd(r[i],a[i]);
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans,gcd(l[i],r[i]));
    cout<<ans<<endl;
}