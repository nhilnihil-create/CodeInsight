#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
//const long long MOD = ;
const long long INF_LL = 1e18+3; const int INF_int = 1e9+3;
#define ll long long
#define rep(i,n) for(int i = 0;i<n;i++)
#define lrep(i,n) for(long long i = 0;i<n;i++)
#define All(a) a.begin(),a.end()
#define Debug_Output_ALL(a) for(auto itr = a.begin();itr!=a.end();itr++) cout << *itr << " ";cout << endl;
int main(){
    int k;
    cin >> k;
    ll a[k];
    rep(i,k) cin >> a[i];
    reverse(a,a+k);
    ll minans,maxans;
    if(a[0]!=2){
        cout << -1 << endl;
        return 0;
    } 
    minans = 2LL;maxans = 3LL;
    for(int i  = 1;i<k;i++){
        ll max_multiple = (maxans/a[i])*a[i];
        ll min_multiple = ((minans+a[i]-1LL)/a[i])*a[i];
        if(min_multiple>maxans && max_multiple<minans){
            cout << -1 << endl;
            return 0;            
        }
        maxans = max_multiple+a[i]-1LL;
        minans = min_multiple;
    }
    cout << minans << " " << maxans << endl;
}