#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod ((ll)(1e9)+7)
#define MAX 200000

ll d[MAX+1], s[MAX+1];

int main(){
	int n;
	cin >> n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int c;
		cin >> c;
		if(v.size()==0 || *(v.end()-1)!=c) v.push_back(c);
	}
	n=v.size();

	d[0]=1;
	for(int i=0; i<n; i++){
		d[i+1]=(d[i]+s[v[i]])%mod;
		s[v[i]]+=d[i];
	}
	cout << d[n] << endl;
	return 0;
}