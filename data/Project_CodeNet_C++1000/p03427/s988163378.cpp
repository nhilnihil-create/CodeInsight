#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,count = 0;
  cin >> N;
  long long sN = N;
  int sw = 0;
  while(sN > 9){
    if(sN % 10 != 9){
		sw = 1;
    }
    count++;
    sN /= 10;
  }
    if(sw == 0){
      cout << sN + count*9 << endl;
    }else{
      cout << sN - 1 + count * 9 << endl;
    }
}