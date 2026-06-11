#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n,h;cin>>n>>h;
    int a[n],b[n];rep(i,n)cin>>a[i]>>b[i];
    
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
    
    int ans = 0;
    int i=0;
    while(b[i]>a[0]){
        h-=b[i];
        ++ans;
        ++i;
        if(h<=0 ||i==n)break;
    }
    if(h>0){
    ans+=h/a[0];
    if(h%a[0] != 0)++ans;
    }

    cout<<ans<<endl;
	return 0;
}