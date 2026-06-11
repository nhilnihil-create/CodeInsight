#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
void Main(){
    ll n;cin>>n;
    ll m;cin>>m;
    vector<pair<ll,ll>> ab(n);
    For(i,0,n) cin >> ab[i].first >> ab[i].second;
    sort(ALL(ab));
    For(i,0,n){
        ll num = min(m,ab[i].second);
        ans += num * ab[i].first;
        m-=num;
        if(m==0) break;
    }
    cout << ans << endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}