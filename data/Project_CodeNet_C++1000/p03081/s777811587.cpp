#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;




int n,q;
string s;
char t[maxn], d[maxn];


bool sim(int start, int dest) {
    int at = start;
    for (int i=0; i<q; i++) {
	if (s[at] == t[i]) {
	    if (d[i]=='L') at--;
	    if (d[i]=='R') at++;
	}
	if (at==dest) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>q;
    cin>>s;
    s="*"+s+"*";
    for (int i=0; i<q; i++) {
	cin>>t[i]>>d[i];
    }

    int fell = 0;

    {
	int lo = 0;
	int hi = n+1;
	while (hi-lo>1) {
	    int mid=(lo+hi)/2;
	    if (sim(mid, 0)) {
		lo = mid;
	    } else {
		hi = mid;
	    }
	}
	fell += lo;
    }

    {
	int lo = 0;
	int hi = n+1;
	while (hi-lo>1) {
	    int mid=(lo+hi)/2;
	    if (sim(mid, n+1)) {
		hi = mid;
	    } else {
		lo = mid;
	    }
	}
	fell += (n+1-hi);
    }

    int alive = n - fell;
    cout<<alive<<endl;
    
    return 0;
}
