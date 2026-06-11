#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

template<typename T>
void trace(T *a, int s, int n) {
    for (int i=s; i<n; i++) {
	cout<<a[i]<<" ";
    }
    cout<<endl;
}



typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;
const int inf = 1e9;

int n, m;
vector<int> digits;
int maxlen[maxn]; //max length when using i sticks


void relax(int& x, int y) {
    x=max(x,y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    int cost[10]={0,2,5,5,4,5,6,3,7,6};

    cin>>n>>m;

    for (int i=0; i<m; i++) {
	int d; cin>>d;
	digits.push_back(d);
    }

    for (int i=0; i<=n; i++) {
	maxlen[i]=-inf;
    }
    maxlen[0]=0;

    
    for (int i=0; i<=n; i++) {
	for (int d: digits) {
	    if (cost[d]+i>n) continue;
	    relax(maxlen[i+cost[d]], maxlen[i]+1);
	}
    }

    int have = n;
    string res="";
    
    while (have>0) {
	int x=0;
	for (int d: digits) {
	    if (cost[d]>have) continue;
	    if (maxlen[have-cost[d]]+1 == maxlen[have]) {
		x=max(x, d);
	    }
	}

	have -= cost[x];
	res += char('0'+x);
    }

    cout<<res<<endl;    
    return 0;
}
