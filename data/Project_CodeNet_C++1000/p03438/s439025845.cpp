#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll N;
	cin >> N;
	vector<ll> a(N);
	vector<ll> b(N);
	rep(i,N){
		cin >> a[i];
	}
	rep(i,N){
		cin >> b[i];
	}
	ll suma = 0;
	ll sumb = 0;
	rep(i,N){
		suma += a[i];
		sumb += b[i];
	}
	if(suma > sumb){
		cout << "No" << endl;
		return 0;
	}
	
	ll time = sumb - suma;
	
	ll count1 = 0;
	ll count2 = 0;
	rep(i,N){
		if (a[i] > b[i]) {
			count1 += a[i] - b[i];
		}
		if (a[i] < b[i]) {
			count2 += (b[i] - a[i] + 1) / 2;
		}
	}
	
	if(count1 <= time && count2 <= time){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
    return 0;
}