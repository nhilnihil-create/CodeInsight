#include <iostream>
#include <utility>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, P> PP;

P toll(string s){
    ll h = 0, l = 0;
    int n = s.size();
    ll k = 1;
    for(int i = 0; i < n; i++){
        if(i < 9) l += ((ll)(s[i] - 'a' + 1)) * k;
        else h += ((ll)(s[i] - 'a' + 1)) * k;
        k *= 100;
        if(i == 8) k = 1;
    }
    return P(h, l);
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<PP, int> mp;
    for(int i = 0; i < (1 << n); i++){
        string r = "";
        string b = "";
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) r += s[n * 2 - 1 - j];
            else b += s[n * 2 - 1 - j];
        }
        mp[PP(toll(r), toll(b))]++;
    }
    ll ans = 0;
    for(int i = 0; i < (1 << n); i++){
        string r = "";
        string b = "";
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) r += s[j];
            else b += s[j];
        }
        ans += mp[PP(toll(r), toll(b))];
    }
    cout << ans << endl;
}