/*
      author : nishi5451
      created: 12.08.2020 14:40:47
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,k;
    cin >> n >> k;
    int num = n%2==0 ? n/2 : (n+1)/2;
    if(num >= k) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}