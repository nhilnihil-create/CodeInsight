#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    int MAX_M = 1000003;
    int s; cin>>s;
    int a[MAX_M];
    rep(i,MAX_M) a[i]=0;
    
    a[s]=1;
    
    int ans;
    
    rep(i,MAX_M){
        if(s % 2 == 1)s = 3*s +1;
        else s/=2;
        
        ++a[s];
        if(a[s]==2){
            ans = i+2;
            break;
        }
    }
    cout<<ans<<endl;
	return 0;
}