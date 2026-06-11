#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  int N;
  int a[110000];
  int b[110000];
  int res=0;
  cin >> N;

  a[0]=0;
  rep(i,N) cin >> a[i+1];
  a[N+1]=0;
  int sum=0;
  int prev=a[0];
  FOR(i,0,N+1){
    b[i] = abs(a[i]-prev);
    sum += b[i];
    prev = a[i];
  }

  //  FOR(i,0,N+1)  cout << b[i] << endl;                                       

  for(int i=1;i<=N;i++){
    res = sum - b[i] - b[i+1];
    res += abs(a[i-1]-a[i+1]);
    cout << res << endl;
  }

}
