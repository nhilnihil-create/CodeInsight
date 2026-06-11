 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 1000000007;
 // const ll INF = 1000000000000000000LL;

  vector<bool> Eratosthenes(const int N)
  {
      vector<bool> is_prime(N+1);
      for(int i=0;i<=N;i++)
      {
          is_prime[i] = true;
      }
      vector<int> P;
      for(int i=2;i<=N;i++)
      {
          if(is_prime[i])
          {
              for(int j=2*i;j<=N;j+=i)
              {
                  is_prime[j] = false;
              }
          }
      }
      return is_prime;
  }

int main() {
	int n = 1e5;
	int q;
	cin >> q;
	vector<int> l(q);
	vector<int> r(q);
	rep(i,q){
		cin >> l[i] >> r[i];
	}
	auto is_prime = Eratosthenes(n);
	is_prime[1] = 0;
	// is_prime[0] = false;
	// for(int i=1;i<20;i++){
	// 	cout << i << ':' << is_prime[i] << endl;
	// }
	vector<int> similar(n+1);
	for(int i=3;i<=n;i+=2){
		similar[i] = similar[i-2];
		if(is_prime[i]&&is_prime[(i+1)/2])
			similar[i]++;
	}
	// for(int i=2;i<20;i++){
	// 	cout << i  << ':' << similar[i] << endl;
	// }
	vector<int> ans(n);
	rep(i,q){
		// cout << similar[r[i]] << endl;
		// cout << similar[l[i]] << endl;
		ans[i] = similar[r[i]] - similar[l[i]-2];
	}
	rep(i,q) cout << ans[i] << endl;
	return 0;
}
