#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound 

ll l[100];

void init()
{
  l[0]=2;
  l[1]=1;
  for (int i=2;i<100;i++)
    l[i]=l[i-1]+l[i-2];
}

int main()
{
  int n;cin>>n;
  init();
  cout<<l[n]<<endl;
}
