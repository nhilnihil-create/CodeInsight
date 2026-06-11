#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    
    ll n,z,w;
    cin>>n>>z>>w;
    ll a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    ll ans = abs(w - a[n-1]);
    for(int i=0;i<n;i++){
        a[i] = abs(a[i] - a[n-1]);
    }
    ll now = ans;
    ll cnt = 0;
    ll p = 0;
    for(int i=0;i<n-1;){
        p = -1;
        for(int j=i;j<n-1;j++){
            if(cnt%2 == 0){
                if(chmax(now,a[j])){
                    p = j;
                }
            }
            else{
                if(chmin(now,a[j])){
                    p = j;
                }
            }
        }
        if(p == -1) break;
        i = p;
        cnt++;
    }
    chmax(ans,now);
    cout << ans << endl;

}