#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define out(a) cout<<a<<" "
#define all(a) (a).begin(), (a).end()
#define upper_index(v, a) (int)distance(v.begin(), upper_bound((v).begin(), (v).end(), a))
#define lower_index(v, a) (int)distance(v.begin(), lower_bound((v).begin(), (v).end(), a))
typedef long long ll;
const long long INF = 1e17;

int main(void){
    ll l=2,r=3;
    ll k;
    cin>>k;
    vector<int> a(k);
    rep(i,k) cin>>a[i];
    reverse(a.begin(),a.end());
    rep(i,k){
        ll p,q;
        p=l%a[i];
        q=r%a[i];
        l=(l/a[i]);
        r=(r/a[i]);
        if (p!=0) l+=1;
        if (q!=0) r+=1;
        l*=a[i];
        r*=a[i];
    }
    if (l==r){
        cout<<-1<<endl;
    }else{
        cout<<l<<" "<<r-1<<endl;
    }
    
}
