#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
ll dx[4]={0,1,-1,0};
ll dy[4]={1,0,0,-1};

// スタックオーバーフローの罠を解決する

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int k;
    cin>>k;
    int n = (1<<k);
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans = 0;
    for(int i=1;i<n;i++){
        int ma = 0, mi = 0;
        for(int u=n-1;u>=0;u--){
            u &= i;
            if(ma <= a[u]){
                chmax(mi,ma);
                ma = a[u];
            }
            else chmax(mi,a[u]);
        }
        chmax(ans,mi+ma);
        cout << ans <<"\n";
    }

}