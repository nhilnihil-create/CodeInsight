/*
https://open.spotify.com/track/1nEjpWJlqcOsf2ZaRQ3XdW?si=w4JqYIANSL2OFpe68ZaBdQ

In the particularly cold night
Perhaps you couldn’t sleep well
In the bright morning woken up from sleep
You are full of darkness
You, who were so worried for some reason that you
Hugged me tightly and asked for my love

You broke and ruined my everything
My daily life and even my people yeah
I resent you all day
But to leave you I oh I

Don’t worry babe
I love you babe
I’ll be by your side
Maybe

Maybe

Looks about to collapse but remains
And the cycle continues unsteadily
I’m about to give up but when I see you I Oh I

No babe
I love you babe
I’ll hold your hand
Maybe

Maybe
I’ll be by your side
Maybe
I’ll trust you

Stay with me, stay with me
So you won’t think of anything
I’ll stay here pretending to be reluctant
So hold me back
Maybe

Maybe
I will be by your side
Maybe
I’ll trust you

Maybe

*/

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define for1(i, a, b) for(i = a; i <= b; ++i)
#define for0(i, a, b) for(i = a; i < b; ++i)
#define forw1(i, a, b) for(i = a; i >= b; --i)
#define forw0(i, a, b) for(i = a - 1; i >= b; --i)
#define fora(v, a) for(auto v : a)
#define bp __builtin_popcount
#define bpll __builtin_popcountll

using namespace std;
using cd = complex<double>;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<cd> vcd;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;

const int modd1 = 1e9 + 7, modd2 = 998244353, maxn = 2010, K = 26, inf = 1e9, infll = 1e18;
const double pi = acos(-1);
bitset<maxn * maxn> dp(1);
int n, a[maxn];

void solve(){
    int i, j, k, l, r; cin >> n;
    int s = 0;
    for0(i, 0, n){
    	cin >> a[i]; s += a[i];
	}
	for0(i, 0, n){
		dp |= (dp << a[i]);
	}
	for1(i, (s + 1) / 2, s){
		if(dp.test(i)){
			cout << i; break;
		}
	}
}

signed main() {
    //freopen(".INP", "r", stdin); 
    //freopen(".OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
