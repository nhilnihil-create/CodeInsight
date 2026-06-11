/*
      author : nishi5451
      created: 11.08.2020 20:01:31
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,a;
    cin >> n >> a;
    n %= 500;
    if(n>a) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}