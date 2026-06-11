#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
// b/aで考える
int main(void){
    int n,k;cin>>n>>k;
    ll res=0;
    for(int b=k+1;b<=n;b++){
        int buf=n/b;
        res+=buf*(b-k);
        int buf2=n-buf*b-k+1;
        res+=max(buf2,0);
        //cout<<buf*(b-k)<<" "<<max(buf2,0)<<endl;
        if(k==0)res--;
    }
    
    cout<<res<<endl;
}
