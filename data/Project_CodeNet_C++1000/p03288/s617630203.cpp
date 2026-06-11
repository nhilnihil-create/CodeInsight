#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
#include <set>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define SORT(s) sort((s).begin(),(s).end())

int main(){
    ll R; cin >> R;
    if(R<1200) cout << "ABC" << endl;
    else if(1200<=R && R < 2800) cout << "ARC" << endl;
    else cout << "AGC" << endl;
}
