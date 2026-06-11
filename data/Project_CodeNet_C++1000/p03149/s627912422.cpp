#include <bits/stdc++.h>
#define inp(X) cin >> X
#define out(X) cout << X << endl
#define out16(X) cout << setprecision(16) << X << endl
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define MAX(A) *max_element(A.begin(),A.end())
#define MIN(A) *min_element(A.begin(),A.end())
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vd = std::vector<double>;
using vvd = std::vector<std::vector<double>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using namespace std;
#define MOD 1000000007
#define INF 1000000001
#define LL_INF 1001001001001001001

int main(void) {
	int n1,n2,n3,n4; cin >> n1 >> n2 >> n3 >> n4;
	bool flg[4] = {false};
	int nums[4] = {1,9,7,4};
	rep(i,4){
		if(n1==nums[i] || n2==nums[i] || n3==nums[i] || n4==nums[i] ) flg[i] = true;		
	}
	if(flg[0]&&flg[1]&&flg[2]&&flg[3]) out("YES");
	else out("NO");

}


