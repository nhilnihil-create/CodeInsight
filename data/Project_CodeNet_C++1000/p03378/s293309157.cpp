/*
      author  : nishi5451
      created : 14.08.2020 18:06:54
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    sort(a.begin(),a.end());
    int l = 0, r = 0;
    for(int i=0; i<m; i++){
        if(a[i]<x) l++;
        else r++;
    }
    cout << min(l,r) << endl;
    return 0;
}