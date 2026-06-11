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
    ll s; cin >> s;

    set<ll> a;
    ll count = 1;
    while(a.find(s) == a.end()){
        a.insert(s);
        if(s%2 == 0){
            s /= 2;
        }else{
            s = 3*s + 1;
        }
        count += 1;
    }
    cout << count << endl;

}
