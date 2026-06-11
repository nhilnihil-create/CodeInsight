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
    string s; cin >> s;
    if(s.size() == 1) cout << 0;
    else {
        string s1, s2;
        int c1 = 0, c2 = 0;
        For(i, 0, s.size()) {
            if(i % 2 == 0) {
                s1 += '0';
                s2 += '1';
            }
            else {
                s1 += '1';
                s2 += '0';
            }
        }
        For(i, 0, s.size()) {
            if(s[i] != s1[i]) c1++;
            else if (s[i] != s2[i]) c2++;
        }
        cout << min(c1, c2);

    }

    
    
    
    return 0;
}