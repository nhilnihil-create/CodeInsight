#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 
 
int32_t main()
{
    fast;
    int N, Q; cin >> N >> Q;
    string S; cin >> S;
    vi s(N + 1);
    s[0] = 0; s[1] = 0;
    for (int i = 1; i < N; ++i) {
        if (S[i-1] == 'A' && S[i] == 'C')
        s[i + 1] = s[i] + 1;
        else
        s[i + 1] = s[i];
    }
 
    while(Q--) {
        int l, r; cin >> l >> r;
        cout << s[r] - s[l] << endl;
    }
    
    return 0;
}