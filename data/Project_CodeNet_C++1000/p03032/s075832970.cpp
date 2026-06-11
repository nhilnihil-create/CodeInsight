#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;



ll N, K;

int main(){
	cin >> N >> K;
	
	vector<ll> v(N*2);
	for ( int i = 0; i < N; i++ ){
		cin >> v[i];
		v[i+N] = v[i];
	}
	
	ll score = LLONG_MIN;
	vector<ll> vv(N);
	for ( int i = 0; i <= N; i++ ){
		for ( int j = N; j-i <= N && j-i <= K; j++ ){
			int len = j - i;
			
			copy(v.begin()+i, v.begin()+j, vv.begin());
			sort(vv.begin(),vv.begin()+len);
			
			ll sum = 0;
			for ( int k = 0; k < len; k++ )
				sum += vv[k];
			
			for ( int mlen = 0; len + mlen <= K; ){
				score = max( score, sum );
				
				if ( mlen >= len )
					break;
				sum -= vv[mlen];
				mlen++;
			}
		}
	}
	
	cout << score << endl;
	return 0;
}

