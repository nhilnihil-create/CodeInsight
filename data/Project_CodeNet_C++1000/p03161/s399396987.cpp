#include<bits/stdc++.h>

typedef long long int lli;
typedef long double lld;
typedef long long ll;
//Datatype
#define vi vector<int>
#define vlli vector<long long int>
#define vvi vector<vector<int>>
#define vvlli vector<vector<long long int>>
#define ppi pair<int, int>
#define rppi pair<int, pair<int, int>>
#define lppi pair<pair<int, int>, int>
#define vppi vector<pair<int, int>>
#define sppi stack<pair<int int>>
#define qppi queue<pair<int, int>>
//function
#define f first
#define s second
#define pb(x) push_back(x)
#define mkp(i, j) make_pair(i, j)
#define lmkp(i,j,k) make_pair(make_pair(i,j),k)
#define rmkp(i,j,k) make_pair(i,make_pair(j,k))
//loop
#define loop(i,n) for (i = 0; i < n; ++i)
#define loops(i,k,n) for (i = k; i <= n; ++i)
#define looprev(i,k,n) for (i = k; i >= n; --i)
//Const
#define inf (int)1e9
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
//Print
#define prd(n) printf("%d", n)
#define prl(n) printf("%lld", n)
#define prdn(n) printf("%d\n", n)
#define prln(n) printf("%lld\n", n)
#define prf(n) printf("%f", n)
//Scan
#define scd(n) scanf("%d", &n)
#define scd2(a, b) scanf("%d %d", &a, &b)
#define scd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scl(n) scanf("%lld", &n)
#define scl2(a, b) scanf("%lld %lld", &a, &b)
#define scl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scf(n) scanf("%f", &n)

using namespace std;
class Solution{
  public:
    int frog2(int N, vector<int> vec, int k){
      if(vec.size() == 1){
          return 0;
      }
      else if(vec.size() == 2){
          return abs(vec[1]-vec[0]);
      }
      int i, j, A[N];
      loop(i, N){
          A[i] = INT_MAX;
      }
      A[0] = 0;
      A[1] = abs(vec[1]-vec[0]);
      loops(i, 2, N-1){
          if(i < k){
              loop(j, i){
                  A[i] = min(A[j] + abs(vec[i]-vec[j]), A[i]);
              }
          }
          else{
              loops(j, i-k, i){
                  A[i] = min(A[j] + abs(vec[i]-vec[j]), A[i]);

              }
          }
      }
      return A[N-1];
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli i, j, k, n;
    Solution s;
    cin>>n>>k;
    vector<int> vec(n, 0);
    loop(i, n){
        cin>>vec[i];
    }
    int res = s.frog2(n, vec, k);
    cout<<res<<endl;
  return 0;
}