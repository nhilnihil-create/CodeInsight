/*
      author  : nishi5451
      created : 15.08.2020 00:32:35
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> c(n);
    rep(i,n) cin >> v[i];
    rep(i,n) cin >> c[i];
    int now = 0;
    rep(i,n){
        if(v[i]-c[i]>0)
            now += v[i]-c[i];
    }
    cout << now << endl;
    
    return 0;
}