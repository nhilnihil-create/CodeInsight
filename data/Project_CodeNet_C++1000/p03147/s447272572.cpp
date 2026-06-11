#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    int n;cin>>n;
    int a[n];
    
    rep(i,n) cin>>a[i];
    
    int ans = 0;
    int y;
//    int cc = 0;
    int sum=0;
    rep(i,n)sum+=a[i];
    if(sum==0){
        cout<<0<<endl;
        return 0;
    }

    while(true){
        int x;
        rep(i,n)if(a[i]>0){
            x = i;
            break;
        }
//        int x = lower_bound(a, a + n, 1) - a;
        for(int j = 0; j + x < n; ++j){
            if(a[x+j]==0){
                y = x+j-1;
                break;
            }
            if(j + x == n-1 && a[n-1]>0) {
              y = n-1;
              break;
            }
        }
//        cout<<x<<" "<<y<<endl;
      
        ++ans;
        for(int i = x; i<= y;++i){
         --a[i];   
        }
        
//        rep(i,n)cout<<a[i]<<" ";
//        cout<<endl;

        sum=0;
        rep(i,n) sum+=a[i];
        if(sum==0)break;
    }
    cout<<ans<<endl;
	return 0;
}