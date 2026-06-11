#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n,d,x;cin>>n>>d>>x;
    int a[n];rep(i,n)cin>>a[i];
    int ans = x;
    rep(i,n){
        int tmp=1;
        ++ans;
        while(tmp<=d){
            tmp+=a[i];
            if(tmp<=d)++ans;
        }
    }
    cout<<ans<<endl;
	return 0;
}