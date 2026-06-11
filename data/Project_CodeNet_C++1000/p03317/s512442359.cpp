#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N,K,min = 99999999,f,count = 0;
  cin >> N >> K;
  vector<int> a(N);
  froop1(0,N){
    cin >> a.at(i);
    if(a.at(i) < min){
      min = a.at(i);
      f = i;
    }
  }
      count += (N - 1) / (K - 1);
      if((N - 1) % (K - 1) != 0) count++;
  cout << count << endl;
return 0;
}