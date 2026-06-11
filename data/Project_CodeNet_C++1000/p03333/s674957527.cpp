#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; long long L[100010], R[100010]; 
	L[0] = 0; R[0] = 0; 
	cin >> N; 
	for(int i = 1; i <= N; i++) cin >> L[i] >> R[i]; 
	sort(L, L+N+1, greater<long long>()); 
	sort(R, R+N+1); 
	long long ans = 0; 
	for(int i = 0; i <= N; i++){
		if(L[i] < R[i]) break; 
		ans += L[i] - R[i]; 
	}
	cout << ans * 2 << endl; 
}