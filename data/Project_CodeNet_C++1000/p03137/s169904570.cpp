#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n,m;cin>>n>>m;

    if(n>=m){
        cout<<0<<endl;
        return 0;
    }
    else{
    int a[m];rep(i,m)cin>>a[i];
    sort(a,a+m);
    
    int b[m-1];
    rep(i,m-1)b[i]=a[i+1]-a[i];
    
    sort(b,b+m-1,greater<int>());
    int ans_sub = 0;
    rep(i,n-1)ans_sub+=b[i];
    
    cout<<a[m-1]-a[0]-ans_sub<<endl;
    }
	return 0;
}