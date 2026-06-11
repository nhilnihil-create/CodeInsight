#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int a[4];
    rep(i,4)cin>>a[i];
    int ans=0;
    if(abs(a[2]-a[0])<=a[3])ans=1;
    if(abs(a[1]-a[0])<=a[3] && abs(a[2]-a[1])<=a[3])ans=1;
    if(ans==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}