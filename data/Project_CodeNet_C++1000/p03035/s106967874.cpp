#include <bits/stdc++.h>

#define FOR(i,a,b) for(ll i=a;i<ll(b);i++)
#define REP(i,n) FOR(i,0,n)

#define MOD 10e9+7

using namespace std;

int main(){
int A,B;
cin >> A >> B;
cout << (A<=5 ? 0 : (A<=12 ? B/2:B)) << endl;
return 0;
}
