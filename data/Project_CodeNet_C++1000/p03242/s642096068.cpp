#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define SORT(s) sort((s).begin(),(s).end())

int main(){
    string n; cin >> n;
    REP(i,3){
        if(n[i] == '1') n[i] = '9';
        else n[i] = '1';
    }
    cout << n << endl;
}
