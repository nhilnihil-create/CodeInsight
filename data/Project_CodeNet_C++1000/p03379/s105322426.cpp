#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,mid = 0;
  int sw = 0;
  cin >> N;
   vector<long long> a(N);
  vector<long long> b(N);
    froop1(0,N){
      cin >> a.at(i);
      b.at(i) = a.at(i);
    }
  sort(b.begin(),b.end());
  mid = b.at(b.size() / 2) - 1;
  int n = b.size() / 2 - 1;
  froop1(0,N){
   if(a.at(i) <= mid){
     cout << b.at(n + 1);
   }else{
     cout << b.at(n);
   }
    cout << endl;
  }
      
  return 0;
}