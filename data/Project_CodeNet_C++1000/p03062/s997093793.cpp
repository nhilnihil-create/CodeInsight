#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, a[100001], ts;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
		ts += a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 1; i<n; i+=2){
		if(a[i] + a[i+1] < 0)
			ts += 2 * abs(a[i] + a[i+1]);
	}

	cout << ts << endl;

	cout.flush();
	return 0;
}