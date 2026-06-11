#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define rep(i,n) for(int i = 0;i<(int)n;++i)

//read_kaisetsu
int main() {
    int n;cin>>n;
    int c_a = 0;
    int c_b = 0;
    int c_ab = 0;
    int ans = 0;
    
    rep(i,n){
        string s;cin>>s;
        int m = s.size();
        rep(j,m-1)if(s[j]=='A' && s[j+1] =='B')++ans;
        if(s[m-1]=='A' && s[0]=='B')++c_ab;
        else if(s[0]=='B')++c_b;
        else if(s[m-1]=='A')++c_a;
    }
    int ans2 = c_ab + min(c_a, c_b);
    if(c_ab > 0 && c_a == 0 && c_b ==0)--ans2;
    cout<<ans + ans2<<endl;
	return 0;
}