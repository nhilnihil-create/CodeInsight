/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.

*/
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;

int mod = 1000000007;
ll dp[100005];;

ll gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}

bool compare(pair<int,int>p1, pair<int,int>p2){

  return p1.second > p2.second;
 }

 int main(){

  int a[3];

  for(int i=0;i<3;i++){
    cin>>a[i];
  }

 sort(a,a+3);
  long long sum =0;

 for(int i=0;i<2;i++){
    sum += a[i+1]-a[i];
 }

 cout<<sum<<endl;

 return 0;
 }