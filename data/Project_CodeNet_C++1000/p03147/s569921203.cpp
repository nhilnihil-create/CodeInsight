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
  int N; cin >> N;
  int h[N]; rep(i,N) cin >> h[i];
  int retval = 0, l=0;

  while (l<N){
    if (h[l]==0) {
      l++;
      continue;
    }
    int i=l;
    while (i<N && h[i]>0){
      h[i]--;
      i++;
    }

    retval++;
  }
  cout << retval << endl;
  
  // cout << fixed << setprecision(10);
  
  return 0;
}

