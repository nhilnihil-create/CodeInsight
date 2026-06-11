#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0;i < (int)n;++i)

int main() {
    int n,t;cin>>n>>t;
    int ans = 9999;
    rep(i,n){
        int c,t2;cin>>c>>t2;
        if(t2<=t)ans = min(ans,c);
    }
    if(ans==9999)cout<<"TLE"<<endl;
    else cout<<ans<<endl;
    
	return 0;
}