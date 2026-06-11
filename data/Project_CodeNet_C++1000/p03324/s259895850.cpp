#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,M;
  cin >> N >> M;
  long long sum = 1;
  froop1(0,N) sum *= 100;
  long long sum2 = sum * M;
  if(M == 100){
   sum2 += sum; 
  }
    
  cout << sum2 << endl;

return 0;
}