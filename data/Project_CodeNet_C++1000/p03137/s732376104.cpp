#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;


int n, m;
int x[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
	cin>>x[i];
    }
    sort(x,x+m);
    vector<int> gap;
    for (int i=0; i+1<m; i++) {
	gap.push_back(x[i+1]-x[i]);
    }

    sort(gap.begin(), gap.end());
    for (int i=0; i<n-1 && !gap.empty(); i++) {
	gap.pop_back();
    }

    int res  = std::accumulate(gap.begin(), gap.end(), 0);
    out(res);    
    
    return 0;
}
