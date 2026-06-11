#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    string s;cin>>s;
    int ans = 0;
    
    rep(i,n){
        int a[26],b[26];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        rep(j,i){
            int m = s[j]-'a';
            a[m]=1;
        }
        for(int k = i;k<n;++k){
            int m = s[k]-'a';
            b[m]=1;
        }
        int tmp = 0;
        rep(i,26)tmp+=a[i]*b[i];
        ans = max(ans,tmp);
    }
    cout<<ans<<endl;
	return 0;
}