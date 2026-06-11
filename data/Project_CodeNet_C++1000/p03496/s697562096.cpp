#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll a[n+1], m=0;
	int m_idx;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(abs(a[i])>=abs(m)){
			m=a[i];
			m_idx=i;
		}
	}

	cout << 2*n-1 << endl;
	for(int i=1; i<=n; i++){
		cout << m_idx << " " << i << endl;
	}
	if(m>=0){
		for(int i=1; i<n; i++){
			cout << i << " " << i+1 << endl;
		}
	}else{
		for(int i=n; i>1; i--){
			cout << i << " " << i-1 << endl;
		}
	}
	return 0;
}