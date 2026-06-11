#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define req(i,n) for(int i = 1;i <=n;i++)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

//最大公約数
int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}

//最小公倍数
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}

//素数判定
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}



  








      

 
  int main() {
   
    int MAX = 101010;
    
    vector <int> is_prime(MAX,1);
    is_prime[0] = 0,is_prime[1] = 0;
    for (int i = 2;i < MAX;i++){
      if (!is_prime[i]) continue;
      for (int j = i*2;j < MAX;j += i) is_prime[j]=0;
    }
    vector <int> a(MAX,0);
    for (int i = 0;i < MAX;i++){
      if (i % 2 == 0) continue;
      if (is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
    }

    vector <int> s(MAX+1,0);
    for (int i = 0;i < MAX;i++) s[i+1]=s[i]+a[i];






    int n;
    cin >> n;
    int l[n+1],r[n+1];
    rep (i,n){
      cin >> l[i] >> r[i];
      ++r[i];
    }
    rep (i,n){
      cout << s[r[i]] - s[l[i]] << endl;
    }

    
}


