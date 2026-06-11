#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<=(int)n;++i)

//read_kaisetu
int main() {
    string s;cin>>s;
    int n = s.size();
    int ans = n + 1;
    rep(i,n-1){
        if(s[i+1]!=s[i])ans = min(ans, max(i + 1, n - i -1));
    }
    if(ans == n + 1)ans = n;
    cout<<ans<<endl;
	return 0;
}