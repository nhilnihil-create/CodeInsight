#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int a[n];rep(i,n)cin>>a[i];
    sort(a,a+n);
    int sum = 0;
    rep(i,n-1)sum+=a[i];
    if(a[n-1]>=sum)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
	return 0;
}