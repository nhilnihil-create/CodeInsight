#include <iostream>
#include <iomanip>
#include <string>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    string n;
    cin >> n;
    int ans = 0;
    repi(i,n.size(),0){
        if(n[i] == '2')ans++;
    }
    cout << ans << endl;
    return 0;
}