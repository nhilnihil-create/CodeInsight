/// Kazuki Hoshino


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define dmp(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
//#define endl '\n'
typedef tree<
int,
null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;
int n,x,a[202020],ans,sum[202020], fac[202020];
signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
cin >> n >> x;
for(int i=1;i<=n;i++){
    cin >> a[i];
}
reverse(a+1,a+n+1);
for(int i=1;i<=n;i++){
    sum[i]=sum[i-1]+a[i];
}
for(int i=1;i<=n;i++){
    if(i==1)fac[i]=5;
    else 
    fac[i]=2*i + 1;
}
ans = 1e18;
for(int i=1;i<=n;i++){
    int cur = i*x;
    for(int j=0;j<n;j+=i){
        int pre = sum[min(n,j+i)]-sum[j];
        if(fac[j/i]>ans/pre){
            cur = ans;
            break;
        }
        cur+= pre*fac[(j+i)/i];
        if(cur>ans)break;
    }
    ans = min(ans,cur);
}
cout << ans+n*x << endl;
return 0;
}
///....
