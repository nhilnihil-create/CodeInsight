#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl

string s, t, ans;
int main() {
    cin >> s >> t;

    int sl = s.length();
    int tl = t.length();

    if(sl < tl){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    if(sl == tl){
        rep(i, 0, sl){
            if(s[i] == '?') s[i] = t[i];
        }
        if(s == t) cout << s << endl;
        else cout << "UNRESTORABLE" << endl;
        return 0;
    }

    reverse(ALL(s));
    reverse(ALL(t));

    bool found = false;
    rep(i, 0, sl - tl){
        rep(k, 0, tl){
            if(s[i+k] != t[k] && s[i+k] != '?'){
                found = false;
                break;
            }else found = true;
        }
        if(found) {
            rep(k, 0, tl){
                s[i+k] = t[k];
            }
            rep(k, 0, sl) if(s[k] == '?') s[k] = 'a';
            reverse(ALL(s));
            break;
        }
    }

    if(found) cout << s << endl;
    else cout << "UNRESTORABLE" << endl;

    return 0;
}
