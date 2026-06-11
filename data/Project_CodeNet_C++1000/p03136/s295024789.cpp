/*
      author  : nishi5451
      created : 14.08.2020 23:34:29
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(),l.end());
    int sum = 0;
    rep(i,n-1) sum += l[i];
    if(sum>l[n-1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}