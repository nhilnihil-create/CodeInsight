/*Step by step, my body’s bouncing
Close your eyes and dance like the flow of the waves
Feels like I could fly to space
I keep humming lululu
A fair skinned child
Like going to an amusement park
Holding up her arms
Like riding the Viking
She has fallen in love, feel
Heartbeat beating so loud
As if she’ll kiss you
On your fluffy cheeks

Ok turn up the rhythm
That flirty girl
Who smiled at you last time
She’s kinda pretty today
Maybe I’m crazy
The ambulance goes beep bo beep bo
But then again
I’m dancing along

Jumping with my round butt
High till I can touch the clouds
Bungee jumping from above
Where am I right now?

Up on the jelly
Up on the jelly
Up on the up on the
Up on the jelly
Up on the jelly
Up on the jelly
Up on the up on the
Up on the jelly

Step by step, my body’s bouncing
Close your eyes and dance like the flow of the waves
Feels like I could fly to space
I keep humming lululu

Drunk with the scent of sweet fruit
My clear eyes get hazy
I feel good even if someone calls me ugly
I’ll stick my tongue out to the antis
My smile will reach my ears
Like a big eyed frog
The taste of the voice in my ears
Like sugar coated lemon

Jumping with my round butt
High till I can touch the clouds
Bungee jumping from above
Where am I right now?
Up on the jelly
Up on the jelly
Up on the up on the
Up on the jelly
Up on the jelly
Up on the jelly
Up on the up on the
Up on the jelly

Up on the jelly
Up on the jelly
Up on the up on the
Up on the jelly
Up on the jelly
Up on the jelly
Up on the up on the
Up on the jelly*/

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

const int modd1 = 1e9 + 7, modd2 = 998244353, maxn = 10, K = 26, inf = 1e9, infll = 1e18;
const double pi = acos(-1);

void solve(){
    int a, b, i, j; 
    cin >> a >> b;
    int ans = 0; int it = a;
    if(b <= 4){
        for1(i, a, b){
            ans ^= i;
        }
        cout << ans ; return;
    }
    while(it % 4 != 2){
        it++;
    }
    int ed = b;
    while(ed % 4 != 1){
        ed--;
    }
    if(ed < it){
        for1(i, a, b){
            ans ^= i;
        }
    }
    else{
        for1(i, a, it - 1){
            ans ^= i;
        }
        for1(i, ed + 1, b){
            ans ^= i;
        }
    }
    cout << ans;
}

signed main() {
    //freopen(".INP", "r", stdin); 
    //freopen(".OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
