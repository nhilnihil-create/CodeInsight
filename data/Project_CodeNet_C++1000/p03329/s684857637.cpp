#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0;i<=(int)n;++i)

//shakyo
int main() {
    int n;cin>>n;
    int ans = n;
    rep(i,n){
        int cc = 0;
        int t = i;
        while(t>0)cc+=t%6,t/=6;
        t = n - i;
        while(t>0)cc+=t%9,t/=9;
        
        if(cc < ans)ans=cc;
    }
    cout<<ans<<endl;
	return 0;
}