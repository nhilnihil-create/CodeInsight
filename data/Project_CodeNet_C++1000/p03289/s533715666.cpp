#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();
    if (s[0]!='A') out("WA");

    bool saw = false;
    int x=-1;
    for (int i=2; i<n-1; i++) {
	if (s[i]=='C') {
	    if (saw) out("WA");
	    saw=true;
	    x=i;
	}
    }
    if (!saw) out("WA");


    for (int i=1; i<n; i++) {
	if (i==x) continue;
	if (s[i]>='A' && s[i]<='Z') out("WA");
    }

    out("AC");

    return 0;
}
