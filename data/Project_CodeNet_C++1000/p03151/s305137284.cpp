#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
int main(){
    int n;
    cin>>n;
    vector<int64_t> a(n),b(n);
    int64_t suma=0,sumb=0;
    rep(i,n){
        cin>>a[i];
        suma += a[i];
    }
    rep(i,n){
        cin>>b[i];
        sumb += b[i];
    }
    if(suma<sumb){
        cout<<-1<<endl;
        return 0;
    }
    int ans=0;
    int64_t husoku=0;
    rep(i,n){
        if(a[i]<b[i]){
            ans++;
            husoku += b[i]-a[i];
        }
    }
    vector<int64_t> sa(n);
    rep(i,n){
        sa[i]=a[i]-b[i];
    }
    all(sa);
    //reverse(sa.begin(),sa.end());
    Re(sa);
    rep(i,n){
        if(sa[i]>0&& husoku>0){//ここに入れる
            husoku = husoku -min(sa[i],husoku);
            ans++;
        }
    }
    cout<<ans<<endl;
}