#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e5 + 5;


int n, C;

int a[32][maxn];
int act[maxn];


//note: events trick fails b/c the recorder needs
//to be loaded into the channel 0.5 seconds before it starts recording

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>C;
    for (int i=0; i<n; i++) {
	int s,t,c; cin>>s>>t>>c;
	for (int j=s; j<t; j++) {
	    a[c][j]=1;
	}
    }


    for (int i=0; i<=int(1e5); i++) {
	for (int j=1; j<32; j++) {
	    if (a[j][i] || a[j][i+1]) {
		act[i]++;
	    }
	}
    }

    int res = 0;
    for (int i=1; i<=int(1e5); i++) {
	res = max(res, act[i]);
    }

    out(res);
    
    return 0;
}
