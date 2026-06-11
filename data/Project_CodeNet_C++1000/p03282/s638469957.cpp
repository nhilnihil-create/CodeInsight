#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

string s;
ll k , p = 0;

int main()
{
    _FastIO;
    cin >> s;
    ll n = s.size();
    cin >> k;
    char c;
    for(ll i = 0; i < n; i++){
        if(s[i] != '1'){
            p = i + 1;
            c = s[i];
            break;
        }
    }
    if(!p || k < p){
        cout << "1" << endl;
        return 0;
    }
    cout << c << endl;
    return 0;
}
