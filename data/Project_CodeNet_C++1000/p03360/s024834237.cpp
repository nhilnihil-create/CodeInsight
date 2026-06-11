/*
      author  : nishi5451
      created : 14.08.2020 18:17:59
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    vector<int> a(3);
    int k;
    cin >> a[0] >> a[1] >> a[2];
    cin >> k;
    int sum = 0;
    sort(a.begin(),a.end());
    while(k--){
        a.back()*=2;
    }
    rep(i,3) sum += a[i];
    cout << sum << endl;
    return 0;
}