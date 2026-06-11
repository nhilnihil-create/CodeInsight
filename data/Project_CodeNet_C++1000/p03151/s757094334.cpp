#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    long n,cnta=0,cntb=0;
    cin >> n;
    long a[n],b[n];
    rep(i,n){
        cin >> a[i];
        cnta += a[i];
    } 
    rep(i,n){
        cin >> b[i];
        cntb += b[i];
    } 
    if(cnta<cntb) cout << -1 << endl;
    else{
        long cur = 0,ans=0;
        vector<long> d;
        rep(i,n){
            if(a[i]<b[i]){
              cur += b[i]-a[i];
              ans++;
            } 
            else  d.push_back(a[i]-b[i]);
        }
        sort(d.begin(),d.end());
        reverse(d.begin(),d.end());
        for(auto i:d){
            if(cur>0){
                cur -= i;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
