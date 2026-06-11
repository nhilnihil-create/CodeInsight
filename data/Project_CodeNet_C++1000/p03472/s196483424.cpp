# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
ll maxi,sum,n,h,a[100005],b[100005];    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>h;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        maxi=max(maxi,a[i]);
    }
    sort(b+1,b+n+1);
    reverse(b+1,b+n+1); 
    int idx=0;
    for(int i=1;i<=n;i++){
        if(b[i]<maxi) break;
        sum+=b[i];
        if(sum>=h){
            cout<<i<<endl;
            return 0;
        }
        idx=i;
    }
    ll sisa=h-sum;
    ll ans=sisa/maxi;
    if(sisa%maxi!=0) ans++;
    cout<<ans+idx<<endl;
}