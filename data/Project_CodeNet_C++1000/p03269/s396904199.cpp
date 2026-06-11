#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;


int L;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>L;

    int hi=0;

    const int N = 20;


    vector<pair<int,int>> v;

    for (int i=2; i<=N; i++) {
	int ways = 1<<(N-i);
	while (hi+ways<=L) {
	    v.push_back({i, hi});
	    hi += ways;
	}
    }


    int nodes = N;
    int edges = (N-2)*2 + (int)v.size();

    cout<<nodes<<" "<<edges<<"\n";

    for (int i=2; i<N; i++) {
	int wei = 1<<(N-1-i);
	cout<<i<<" "<<i+1<<" "<<wei<<"\n";
	cout<<i<<" "<<i+1<<" "<<0<<"\n";
    }


    for (auto ed: v) {
	cout<<1<<" "<<ed.first<<" "<<ed.second<<"\n";
    }


    return 0;
}
