#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(long long i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N,M;
  cin >> N >> M;
  cout << N*M - M - N + 1 << endl;
}