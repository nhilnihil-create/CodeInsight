/*
      author  : nishi5451
      created : 14.08.2020 18:14:34
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    int tot=0;
    rep(i,n){
        cin >> a[i];
        tot += a[i];
    }
    sort(a.begin(),a.end());
    cout << n+(x-tot)/a.front() << endl;
    return 0;
}