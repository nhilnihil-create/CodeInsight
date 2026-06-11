#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=110,K=100010;
int a[N];
bool dp[K];
int n,k;

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<=k;++i)
		for(int j=0;j<n;++j)
			if(i-a[j]>=0)
				dp[i]|=!dp[i-a[j]];
	cout<<(dp[k]?"First":"Second")<<endl;
}
