#include<bits/stdc++.h>
#define MAX_N 100001
#define INF_INT 2147483647
#define INF_LL 9223372036854775807
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
void init(int n);
int find(int n);
void unite(int x,int y);
bool same(int x, int y);
ll bpow(ll,ll,ll);
typedef vector<int> vec;
typedef vector<vec> mat;
mat mul(mat &A,mat &B);
mat pow(mat A,ll n);
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
const int MOD = 1000000007;

string  S;


int main()
{
  cin >> S;
  int t,d;
  vector<int> v(0);
  for(int i=0;i<S.size()-1;i++){
    if(S[i] != S[i+1])
      v.push_back(max(i+1,(int)S.size()-i-1));
  }
  if(v.size() == 0){
    cout << S.size() << endl;
  }else{
    sort(v.begin(),v.end());
    cout << v[0] << endl;
  }
  return 0;
}

int par[MAX_N];
int ranks[MAX_N];

//n要素で初期化
void init(int n){
  REP(i,n){
    par[i] = i;
    ranks[i] = 0;
  }

}

