#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n;
    cin >> n;
    string s[n];
    for(ll i = 0; i < n; i++)
        cin >> s[i];
    ll a = 0, b = 0, ab = 0;
    ll same = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < s[i].length()-1; j++){
            if(s[i][j]=='A' && s[i][j+1]=='B') ab++;
        }
        if(s[i][s[i].length()-1]=='A') a++;
        if(s[i][0]=='B') b++;
        if(s[i][0]=='B'&&s[i][s[i].length()-1]=='A')
            same++;
    }
    //cout << a << " " << b << " " << ab  << " " << same<< endl;
    ll ans = ab+min(a, b);
    if(same==a&&same==b&&same!=0) ans--;
    cout << ans << endl;
    return 0;
}
