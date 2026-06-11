#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int a[100];rep(i,100)a[i]=0;
    
    for(int i=2;i<=n;++i){
        int t=i;
        int j=2;
        while(t>1){
            while(t%j==0){
                ++a[j];
                t/=j;
            }
            ++j;
        }
    }
    int ans=0;
    int c75=0;
    int c25=0;
    int c15=0;
    int c5=0;
    int c3=0;
    
    rep(i,n){
        if(a[i]>=74)++c75;
        if(a[i]>=24)++c25;
        if(a[i]>=14)++c15;
      if(a[i]>= 4)++c5;
        if(a[i]>= 2)++c3;
    }
    ans+=c75;
    ans+=max(c25*(c3-1),0);
    ans+=max(c15*(c5-1),0);
    ans+=max(c5*(c5-1)/2*(c3-2),0);

    cout<<ans<<endl;
	return 0;
}