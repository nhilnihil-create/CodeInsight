#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int N, H; cin >> N >> H;
  int a[N], b[N];
  rep(i,N){
    cin >> a[i] >> b[i];
  }

  sort(a,a+N);
  sort(b,b+N);

  int max_a = a[N-1];
  int cnt_b = N - (lower_bound(b,b+N,max_a) - b);
  
  ll retval = 0;
  for (int i=0;i<cnt_b;i++){
    H -= b[N-1-i];
    if (H<=0) {
      retval = i+1;
      break;
    }
  }
  if (H>0) retval = cnt_b + (H+(max_a-1ll))/max_a;
  cout << retval << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}

