#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define ALL(v) (v).begin(), (v).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;


int main(){
    ll n;
    ll suma=0;
    ll sumb=0;
    ll husoku=0; 
    cin>>n;
    VL a(n,0), b(n,0), yoyu;
    ll cnt=0;
    rep(i,0,n){
        cin >> a[i];
        suma += a[i];
    }
    rep(i,0,n){
        cin >> b[i]; 
        sumb += b[i];
        if(a[i]<b[i]){
            husoku += b[i]-a[i];
            cnt++;
        }
        else yoyu.push_back(a[i]-b[i]);
    }
    sort(ALL(yoyu)); 
    reverse(ALL(yoyu));
    if(suma < sumb){
        cout << -1 << endl;
        return 0;
    }
    ll id=0;
    while(husoku>0){
        husoku-=yoyu[id]; id++;
    }
    cout << cnt+id << endl;
}