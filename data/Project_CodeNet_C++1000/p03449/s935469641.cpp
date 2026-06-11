#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG
int main(){
    int n;
    cin>>n;
    int a1[n];
    int a2[n];
    rep(i,n){
        cin>>a1[i];
    }
    rep(i,n){
        cin>>a2[i];
    }
//累積和作成
    int s1[n+1];
    int s2[n+1];
    s1[0]=0;
    s2[0]=0;
    rep1(i,n){
        s1[i]=s1[i-1]+a1[i-1];
        s2[i]=s2[i-1]+a2[i-1];
    }
int ans=0;
rep1(i,n){
    int sum;
    sum=s1[i]+(s2[n]-s2[i-1]);
    ans=max(ans,sum);
}
cout<<ans<<endl;


}