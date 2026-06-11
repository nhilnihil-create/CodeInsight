#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);

	int N,x; cin>>N>>x;
	vector<int> a(N),b(N); rep(i,N) cin>>a[i];

	sort(a.begin(),a.end());

	for(int i=0; i<N; i++){
		if(x>=a[i]){
			b[i]=a[i];
			x -= a[i];
		}

		if(i==N-1){
			b[i] += x;
		}
	}
	
	int ct=0;
	for(int i=0; i<N; i++){
		if(a[i]==b[i]) ct++;
	}
	cout << ct << endl;
}
