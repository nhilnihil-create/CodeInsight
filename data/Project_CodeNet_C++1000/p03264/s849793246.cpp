/*
      author : nishi5451
      created: 11.08.2020 20:53:45
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int k;
    cin >> k;
    int ans;
    if(k%2==0) cout << (k/2)*(k/2) << endl;
    else cout << (k-1)/2*((k-1)/2+1) << endl;
    return 0;
}