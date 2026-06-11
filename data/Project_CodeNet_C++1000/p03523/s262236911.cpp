#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
typedef pair<ll,ll> pll;


string s, a;
int main()
{
        cin >> s;
        a = "AKIHABARA\n";
        ll ptr = 0;
        ll i = 0;
        while(i < 9){
                if(ptr < s.length() && s[ptr] == a[i]) {
                        i++; ptr++;
                }else {
                        if(a[i] == 'A') {
                                i++;
                        }else {
                                cout << "NO\n"; return 0;
                        }
                }
        }
        if(ptr == s.length()) cout << "YES\n";
        else cout << "NO\n";
        return 0;
}
