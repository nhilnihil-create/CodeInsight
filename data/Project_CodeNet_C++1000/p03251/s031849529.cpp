#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n,m,x,y;
int a[maxn],b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>m>>x>>y;
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }
    for (int i=0; i<m; i++) {
	cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);

    for (int z=x+1; z<=y; z++) {
	if (a[n-1]<z && b[0]>=z) out("No War");
    }

    out("War");
    
    
    return 0;
}
