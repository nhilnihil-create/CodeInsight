#include <iostream>
#include<string>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<set>
#include <limits>
#include <numeric>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define reprev(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define fi first
#define se second
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
#define MAX_B 1001001
#define NIL -1
#define MOD 1000000007
#define INF 1 << 29
#define INFTY 1000000000000000000LL

int main(){
  int n;cin>>n;
  int a[MAX];
  a[0]=a[n+1]=0;
  rep(i,n)cin>>a[i+1];
  int sum=0;
  rep(i,n+1)sum+=abs(a[i+1]-a[i]);
  for(int i=1;i<n+1;i++){
    int x=a[i-1],y=a[i],z=a[i+1];
    
    cout<<sum-abs(x-y)-abs(y-z)+abs(z-x)<<endl;
  }
}