#include <iostream>
#include <algorithm>
 
#define db(x) cout << "> " << #x << ": " << x << endl;
 
const int N = 200100;
using namespace std;
 
int pos[N];
long long pre_sum[N];
 
inline bool desc(const int &a, const int &b) { return (a > b); }
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	long long x;
	cin >> n >> x;
	
	for(int i = 1; i <= n; i++)
		cin >> pos[i];
	
	sort(pos +1, pos +n +1, desc);
	
	for(int i = 1; i <= n; i++)
		pre_sum[i] = pre_sum[i -1] +pos[i];
	
	long long res = (1ll << 62);
	for(int trips = 1; trips <= n; trips++)
	{
		// cost to pickup and drop
		long long curr_res = 1ll *n *x +1ll *trips *x;
		
		int multiplier = 5;
		int l = 1, r = min(trips +trips, n);
		
		while(l <= n)
		{
			curr_res += 1ll *multiplier *(pre_sum[r] -pre_sum[l -1]);
			multiplier += 2;
			
			// Avoid possible overflow?
			if(curr_res > res)
				break;
					
			l = r +1;
			r = min(r +trips, n);
		}
		
		res = min(res, curr_res);
	}
	
	cout << res << '\n';
	return 0;
}