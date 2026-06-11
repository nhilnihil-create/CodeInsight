#include <iostream>
#include <iomanip>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    string s;
    ll k;
    cin >> s >> k;
    repi(i,k,0){
        if(s[i] != '1'){
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << "1" << endl;
    return 0;
}