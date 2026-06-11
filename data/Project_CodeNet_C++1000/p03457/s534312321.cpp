#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    int n;cin>>n;
    int x0 = 0,y0 = 0,t0 = 0;
    
    rep(i,n) {
        int t,x,y;cin>>t>>x>>y;
        int d = (t-t0)-abs(x-x0)-abs(y-y0);
        if(d>=0 && abs(d)%2==0){
            x0 = x;
            y0 = y;
            t0 = t;
        }
        else {
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
	return 0;
}