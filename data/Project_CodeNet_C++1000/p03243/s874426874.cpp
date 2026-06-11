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
    ll N; cin >> N;
    FOR(i,N,999){
        if(i == 111 
          || i == 222
          || i == 333
          || i == 444
          || i == 555
          || i == 666
          || i == 777
          || i == 888
          || i == 999
          ){
              cout << i << endl;
              break;
          }
    }
}
