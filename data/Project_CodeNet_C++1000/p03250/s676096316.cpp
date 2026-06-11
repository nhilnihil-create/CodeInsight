/*
      author : nishi5451
      created: 11.08.2020 20:57:56
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(max(a,b),c)*10 + a + b + c - max(max(a,b),c) << endl;
    return 0;
}
