/*
      author  : nishi5451
      created : 14.08.2020 15:56:18
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<ll> l(n+1);
    l[0]=2;
    l[1]=1;
    for(int i=1; i<n; i++){
        l[i+1] = l[i] + l[i-1];
    }
    cout << l[n] << endl;
    
    return 0;
}