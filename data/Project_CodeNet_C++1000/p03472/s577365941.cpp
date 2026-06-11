#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	long long H;
	cin >> N >> H;
	vector<long long> a( N );
	vector<long long> b( N );
	for( int i = 0; i < N; i++ )  {
		cin >> a[i] >> b[i];
	}

	long long maxa = *max_element( a.begin(), a.end() );
	sort( b.begin(), b.end(), greater<long long>() );
	long long ans = 0;
	int i = 0;
	while( H > 0 )  {
		if( i < N && b[i] > maxa ) {
			H -= b[i];
			i++;
			ans++;
		}
		else {
			long long n = (H + maxa - 1) / maxa;
			H -= n * maxa;
			ans += n;
		}

	}

	cout << ans << endl;
}
