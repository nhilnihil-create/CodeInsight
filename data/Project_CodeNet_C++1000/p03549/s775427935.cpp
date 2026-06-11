#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;



int main() {
    int n , m ;
    cin >> n >> m;

    ll ans=1; 
    rep(i,m){
      ans *=2;
     }
    cout << ((n-m)*100+1900*m) *ans<< endl;
}