#include<bits/stdc++.h>
#define PI acos(-1.0)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N=2e5+5;
const int MOD=1e9+7;
ll a[N];
ll sum[N];
//ll ans[N];
 
ll gao(int l,int r){  //求区间l,r的和
    return sum[r]-sum[l-1];
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    int n ;
    cin >>n;
    for(int i=1;i<=n;i++)   cin >> a[i];
    for(int i=1;i<=n;i++)   sum[i]=sum[i-1]+a[i]; //求前缀和
    ll l=1,r=3;
    ll ans=1e18+8;
    for(int i=2;i<=n-2;i++){
         while(l+1<i&&abs(gao(1,l)-gao(l+1,i))>=abs(gao(1,l+1)-gao(l+2,i)))//若[1,l+1]和[l+1,i]的距离比[1,l+1]和[l+2,i]的距离小，那么我们就继续加，使得两边尽可能平衡
            l++;
         while(r+1<n&&abs(gao(i+1,r)-gao(r+1,n))>=abs(gao(i+1,r+1)-gao(r+2,n)))
            r++;
         set<ll>st;///利用set的log排序
         st.insert(gao(1,l));
         st.insert(gao(l+1,i));
         st.insert(gao(i+1,r));
         st.insert(gao(r+1,n));
         ans=min(ans,abs(*st.begin()-*prev(st.end())));
    }
    cout << ans << endl;
 
    return 0;
}
