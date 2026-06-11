#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

string s;

int main(void){
    
    cin >> s;
    
    int ans = INT_MAX;
    for(int i = 0; i < s.size() - 1; ++i) if(s[i] != s[i + 1]) ans = min(ans, max(i + 1, (int)s.size() - i - 1)); 
	if(ans == INT_MAX) printf("%d\n", (int)s.size());
	else printf("%d\n", ans);
	
    return 0;
}
