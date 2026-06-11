#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n;
    cin >> n;
    bool ok=false;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    ll asum=0,bsum=0;
    rep(i,n) asum += a[i];
    rep(i,n) bsum += b[i];
    if(asum >= bsum) ok=true;
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    else{
        ll cant=0,cantk=0;
        vector<ll> yoyu(n);
        rep(i,n){
            if(a[i]<b[i]){
                cant += b[i] - a[i];
                cantk++;
            }
            else{
                yoyu.push_back(a[i]-b[i]);
            }
        }
        if(cant == 0){
            cout << 0 << endl;
            return 0;
        }
        sort(yoyu.rbegin(),yoyu.rend());
        rep(i,yoyu.size()){
            cant -= yoyu[i];
            cantk++;
            if(cant<0) break;
        }
        cout << cantk << endl;
        
    }
    
}