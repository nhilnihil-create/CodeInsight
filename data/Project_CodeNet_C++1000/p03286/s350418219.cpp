#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

ll n , k;

int main()
{
    _FastIO;
    cin >> n;
    ll x = 1;
    string s = "";
    while(n){
       if(n % abs(2 * x)){
            n -= x;
            s += '1';
       }
        else
            s += '0';
        x *= (-2);
    }
    reverse(s.begin() , s.end());
    if(s.empty()){
        cout << "0" << endl;
        return 0;
    }
    cout << s << endl;
    return 0;
}
