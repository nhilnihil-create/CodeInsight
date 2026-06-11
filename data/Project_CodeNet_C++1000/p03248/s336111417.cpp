#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mkp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define clr(a, b) memset(a, b, sizeof(a))
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forab(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void nope() {
    cout << -1 << "\n";
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    clock_t tStart = clock();
#endif
    string s; 
    cin >> s;
    int n = s.length();
    if(s[0] != '1' || s[n-1] != '0') {
        cout << "-1\n";
        return 0;
    }
    if(n == 2) {
        cout << "1 2\n";
        return 0;
    }
    if(n == 3) {
        if(s[1] == '0') nope();
        cout << "1 2\n2 3\n";
        return 0;
    }
    int chain = 0;
    forn(i, n/2){	
    	if(s[i] != s[n-2-i]) nope(); 
    	if(s[i] == '1') {
    		if(i != n-2-i)
    			chain += 2;
    		else 
    			++chain;
    	}
    }
    forn(i, chain) 
    	cout << i+1 << " " << i+2 << "\n";
    int num = 2;
    int lst = 0;
    ++chain;
    forab(i, 1, n-1) {
    	if(s[i] == '1') { 
            forab(j, 1, i - lst -1) {
    			++chain;
    			cout << num << " " << chain << "\n";
    		}
    		lst = i;
    		++num;
    	}
    }
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * (clock() - tStart)/ CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
