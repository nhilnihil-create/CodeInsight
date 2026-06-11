#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 500005
#define INF INT_MAX

#define PI   3.14159265358979323846264338327950
 
#define PB push_back 
#define PF push_front
#define F first
#define S second
 
#define fixx(n) fixed << setprecision(n) 
 
#define ll 	 long long 
 
#define mod  1000000007



int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i <= m/10000; i ++){
		for(int j = 0; j <= (m - i*10000)/5000; j ++){
			int k = m- i*10000 - j*5000;
			k /= 1000;
				if(i + j + k == n && (i*10000 + j*5000 + k*1000) == m){
					cout << i << " " << j << " " << k;
					return 0;
				}
			
		}
	}
	cout << "-1 -1 -1";
	return 0;
}