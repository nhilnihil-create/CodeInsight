/*
      author : nishi5451
      created: 11.08.2020 20:13:54
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,x;
    cin >> a >> b >> x;
    if(x>=a && x<=a+b) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}