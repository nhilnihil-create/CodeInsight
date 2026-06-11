#include <iostream>
#include <iomanip>
#include <algorithm>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int n,T;
    cin >> n >> T;
    int cost = INF;
    repi(i,n,0){
        int c,t;
        cin >> c >> t;
        if(t <= T){
            cost = min(cost,c);
        }
    }
    if(cost == INF){
        cout << "TLE" << endl;
    }else{
        cout << cost << endl;
    }
    return 0;
}