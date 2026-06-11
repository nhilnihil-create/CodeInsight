#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

const ll INF = 3e9, MAX = 3e5;
ll a[MAX], sol[MAX];
	
int main(){

	int n; scanf("%d", &n);
 
	for(int i = 0; i < (1 << n); i++) cin >> a[i];
	
 
	for(int i = 0; i < (1 << n); i++)
	{
		ll  mx1 = -INF, mx2 = -INF;
	
		for(int j = i; j >= 0; j = (j - 1)&i)
		{
			
			if(a[j] > mx1)
					mx2 = mx1, mx1 = a[j];
			else{
				if(a[j] > mx2) mx2 = a[j];
			}
			
			if(j == 0) break;
		}
		
		sol[i] = mx1 + mx2;
	}
	
	sol[0] = -INF;
	for(int i = 1; i < (1 << n); i++){
		//~ cout << sol[i] << endl;
	    sol[i] = max(sol[i - 1], sol[i]);	    
	    printf("%lld\n", sol[i]);
	}
	
	return 0;
}
