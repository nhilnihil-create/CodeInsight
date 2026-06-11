

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

/*
B__A
B__A
 __A

*/

int ans;
int A, B, AB;  

int main(void) {
    int n;
    cin >> n;
    rep(i, 0, n) {
        string s;
        cin >> s;
        for(int i=0; i<(int)s.size()-1; i++) {
            if (s[i]=='A' && s[i+1]=='B') ans++;
        }
        if (s[0]=='B') B++;
        if (s[(int)s.size()-1]=='A') A++;
        if (s[0]=='B' && s[(int)s.size()-1]=='A') AB++;
    }
    
    if (AB > 0 && AB == A && AB == B) ans += AB - 1; 
    else ans += min(A, B);

    cout << ans << endl;

	return 0;
}
