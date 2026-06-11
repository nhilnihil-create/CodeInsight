#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 20007;
vector <int> ans;

const int K = 10;

void solve(int n) {
    vector <int> p;
    int pref = max(2ll, n - K); 
    int cur = 0;
    for (int i = 0; i < pref; ++i) {
        p.app(ans[i]);    
        cur += ans[i];
        cur %= 6;
    }

    if (n == 3) {
        cout << "2 5 63" << endl;
        exit(0);
        return;
    }   

    int r = n - pref;
    for (int mask = 0; mask < (1 << (2 * K)); ++mask) {
        if (bp(mask) == r) {
            int add = 0;
            for (int i = 0; i < (2 * K); ++i) {
                if ((mask >> i) & 1) {
                    add += ans[pref + i];
                }   
            }   
            if ((cur + add) % 6 == 0) {
                for (int i = 0; i < (2 * K); ++i) {
                    if ((mask >> i) & 1) {
                        p.app(ans[pref + i]);
                    }   
                }
                for (int e : p)
                    cout << e << ' ';
                cout << endl;
                exit(0);
            }   
        }   
    }

    cout << "GG" << endl;  
    exit(1);
    
}

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int i = 1; i <= 30000; ++i) {
        if (i % 6 == 0 || i % 6 == 2 || i % 6 == 3 || i % 6 == 4) {
            ans.app(i);
        }
    }   
    
    int n;
    cin >> n;
    solve(n);
}