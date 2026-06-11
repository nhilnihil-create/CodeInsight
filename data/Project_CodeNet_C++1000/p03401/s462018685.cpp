#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int a[n];rep(i,n)cin>>a[i];
    int sum=abs(a[0]);rep(i,n-1)sum+=abs(a[i+1]-a[i]);
    sum+=abs(a[n-1]);
    
    rep(i,n){
        int ans = sum;
        if(i==0)ans = ans - abs(a[i]) - abs(a[i+1]-a[i]) + abs(a[i+1]);
        else if(i==n-1)ans =  ans - abs(a[i]) - abs(a[i]-a[i-1]) + abs(a[i-1]);
        else ans = ans - abs(a[i+1]-a[i])- abs(a[i]-a[i-1]) + abs(a[i+1] - a[i-1]);
        
        cout<<ans<<endl;
    }
	return 0;
}