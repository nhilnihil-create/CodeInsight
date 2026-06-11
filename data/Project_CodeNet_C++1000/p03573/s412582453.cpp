/*
      author : nishi5451
      created: 11.08.2020 01:10:02
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b) cout << c << endl;
    else if(b==c) cout << a << endl;
    else if(c==a) cout << b << endl;
    return 0;
}