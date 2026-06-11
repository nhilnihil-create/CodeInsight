#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define IOS cin.tie(0); ios::sync_with_stdio(false)
const int INF = 1e9;
using namespace std;

signed main() {
    string S; cin >> S;
    bool can = false;
    if(S=="KIHBR") can = true;
    if(S=="AKIHBR") can = true;
    if(S=="KIHABR") can = true;
    if(S=="KIHBAR") can = true;
    if(S=="KIHBRA") can = true;
    if(S=="AKIHBRA") can = true;
    if(S=="AKIHABR") can = true;
    if(S=="AKIHBAR") can = true;
    if(S=="KIHABAR") can = true;
    if(S=="KIHABRA") can = true;
    if(S=="KIHBARA") can = true;
    if(S=="AKIHBARA") can = true;
    if(S=="AKIHABRA") can = true;
    if(S=="AKIHABAR") can = true;
    if(S=="KIHABAEA") can = true;
    if(S=="AKIHABARA") can = true;
    if(can) cout << "YES" << endl;
    else cout << "NO" << endl;
}