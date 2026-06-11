/*
      author : nishi5451
      created: 11.08.2020 20:52:22
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b;
    cin >> a >> b;
    int ans = a*b-a-b+1;
    cout << ans << endl;
    return 0;
}