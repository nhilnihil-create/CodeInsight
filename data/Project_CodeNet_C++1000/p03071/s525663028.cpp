/*
      author : nishi5451
      created: 11.08.2020 21:42:10
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    int ans;
    if(a-1>b) ans = 2*a -1;
    else if(b-1>a) ans = 2*b -1;
    else ans = a+b;
    cout << ans << endl;
    return 0;
}