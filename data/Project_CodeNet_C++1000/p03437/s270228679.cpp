#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF= 1000000000000000000;
#define REP(i,n) for(ll i=0; i<n; i++)
#define FOR(i,a,n) for(ll i=a; i<n; i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x,y;
    cin >> x >> y;
    ll k=1;
    //yがxの約数なら-1
    if(x%y==0) {
        cout << -1 << endl;   
    }else{
        cout << x << endl;
    }
}