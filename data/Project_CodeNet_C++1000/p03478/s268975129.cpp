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
  int N, A, B; cin >> N >> A >> B;
  int retval = 0;

  for (int i=1;i<=N;i++){
    int x = i, sum_digit = 0;
    while (x>0){
      sum_digit += x%10;
      x /= 10;
    }
    if (A<=sum_digit && sum_digit<=B) retval += i;
  }

  cout << retval << endl;

  // cout << fixed << setprecision(6);
  return 0;
}
