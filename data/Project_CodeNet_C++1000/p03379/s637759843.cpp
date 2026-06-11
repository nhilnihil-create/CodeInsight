#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n;
    cin >> n;
    vector <long> x(n),y(n);
    rep(i,n){
        cin >> x[i];
        y[i]=x[i];
    } 

    vector <long> ans(n);

    sort(all(y));
    long smid=y[n/2-1];
    long bmid=y[n/2];

    for(int i=0; i<n; i++){
        if(x[i]<bmid){
            ans[i]=bmid;
        }
        else{
            ans[i]=smid;
        }
    }

    rep(i,n) cout << ans[i] << endl;
}
