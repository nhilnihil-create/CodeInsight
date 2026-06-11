/*
      author : nishi5451
      created: 11.08.2020 21:26:28
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ans = b/a;
    if(ans>c) ans = c;
    cout << ans << endl;
    return 0;
}