    #include <iostream>
    #include <sstream>
    #include <iomanip>
    #include <cstdio>
    #include <cstdlib>
    #include <cmath>
    #include <cctype>
    #include <cstring>
    #include <vector>
    #include <list>
    #include <queue>
    #include <deque>
    #include <stack>
    #include <map>
    #include <set>
    #include <algorithm>
    #include <iterator>
    #include <bitset>
    #include <ctime>
    #include <complex>
    using namespace std;
     
    #define FOR(i,a,b) for(LL i = (a); i < (b); i++)
    #define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
    #define ITER(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
    #define FILL(a, value) memset(a, value, sizeof(a))
     
    #define SZ(a) (int)a.size()
    #define ALL(a) a.begin(),a.end()
    #define MP make_pair
    #define PB push_back
     
    typedef long long LL;
    typedef vector<int> VI;
    typedef pair<int,int> PII;
     
    const double PI = acos(-1.0);
    const int INF = 1000 * 1000 * 1000 + 7;
    const LL LINF = INF * (LL) INF;
     
    const int MAX = 705;
     
     
     
    map<pair<string, string>, int> M;
     
    int main()
    {
    	//freopen("In.txt", "r", stdin);
    	int n;
    	string s;
    	cin >> n >> s;
    	
    	FOR(msk, 0, 1 << n) {
    		string R = "", B = "";
    		FOR(i, 0, n) {
    			if (msk & (1 << i)) R += s[i];
    			else B += s[i];
    		}
    		M[MP(R, B)]++;
    	}
    	
    	LL ans = 0;
    	
    	FOR(msk, 0, 1 << n) {
    		string R = "", B = "";
    		FOR(i, 0, n) {
    			if (msk & (1 << i))R += s[n + n - i - 1];
    			else B += s[n + n - i - 1];
    		}
    		ans += M[MP(R, B)];
    	}
    	
    	cout << ans << endl;
    	
    	return 0;
    }