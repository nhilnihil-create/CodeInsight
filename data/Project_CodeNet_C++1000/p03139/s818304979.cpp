#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF= 1LL << 60;
#define REP(i,n) for(ll i=0; i<n; i++)
#define FOR(i,a,n) for(ll i=a; i<n; i++)
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);    
    int n,a,b;
    cin >> n >> a >> b;
    cout << min(a,b) << " " << ((n>=a+b)?0:a+b-n) << endl;

}