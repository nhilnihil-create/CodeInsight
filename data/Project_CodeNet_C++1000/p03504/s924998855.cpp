#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,makichankawaiikakikukeko;
    cin>>n>>makichankawaiikakikukeko;
    int s[n],t[n],c[n];
    for(int i=0;i<n;i++){
        cin>>s[i]>>t[i]>>c[i];
    }
    int a[200002],b[200002];
    memset(b,0,sizeof(b));
    for(int i=1;i<=makichankawaiikakikukeko;i++){
        for(int j=0;j<200002;j++)a[j]=0;
        for(int j=0;j<n;j++)if(c[j]==i){a[s[j]*2-1]++,a[t[j]*2]--;}
        for(int j=1;j<200002;j++)a[j]+=a[j-1];
        for(int j=0;j<200002;j++)if(a[j]>0)b[j]++;
    }
    int ans=0;
    for(int i=0;i<200002;i++)ans=max(ans,b[i]);
    cout << ans<<endl;
    return 0;
}