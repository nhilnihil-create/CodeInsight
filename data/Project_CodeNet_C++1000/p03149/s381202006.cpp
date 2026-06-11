#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
#define vecmin(A) *min_element(A.begin(),A.end())
#define vecmax(A) *max_element(A.begin(),A.end())
typedef long long ll;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(pow(2,a)+pow(2,b)+pow(2,c)+pow(2,d) == pow(2,1)+pow(2,9)+pow(2,7)+pow(2,4)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}