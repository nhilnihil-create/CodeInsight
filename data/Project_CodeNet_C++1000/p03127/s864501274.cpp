#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N;
  cin >> N;
  vector<long long> s(N);
  froop1(0,N){
    cin >> s.at(i);
  }
  long long a = s.at(0);
  froop1(0,N - 1){
    a = gcd(a,s.at(i + 1));
  }
  cout << a << endl;
return 0;
  }