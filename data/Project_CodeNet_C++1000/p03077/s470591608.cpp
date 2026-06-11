#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,A,B,C,D,E,m;
  cin >> N >> A >> B >> C >> D >> E;
  m = N - 1;
	cout << max({m / A,m / B,m / C,m / D,m / E}) + 5 << endl;
}