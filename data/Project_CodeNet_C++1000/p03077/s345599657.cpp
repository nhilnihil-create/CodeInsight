#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,A,B,C,D,E;
  long long minute = 5,m2 = 0,max = 0;
  int m = 0;
  cin >> N >> A >> B >> C >> D >> E;
  vector<long long> p(6,0);
  vector<long long> v(5);
  vector<long long> x(5);
  v.at(0) = A;v.at(1) = B;v.at(2) = C;v.at(3) = D;v.at(4) = E;
  p.at(0) = N;
  froop1(0,5){
    if((N - 1) / v.at(i) > max){
      max = (N - 1) / v.at(i);
    }
  }
minute += max;
  cout << minute << endl;
 
return 0;
}