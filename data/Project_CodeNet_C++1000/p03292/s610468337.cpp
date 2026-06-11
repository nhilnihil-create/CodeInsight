/*
      author : nishi5451
      created: 11.08.2020 20:44:38
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(),a.end());
    cout << abs(a[1]-a[0]) + abs(a[2]-a[1]) << endl;
    return 0;
}