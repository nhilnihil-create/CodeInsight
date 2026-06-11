#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N;
  cin >> N;
  long long sum = 0;
  froop1(0,N){
    int a;
    cin >>a;
    sum += a - 1;
  }
  cout << sum << endl;

return 0;
}