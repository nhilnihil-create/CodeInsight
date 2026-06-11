#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N;
  cin >> N;
  map<long long,long long> num;
  froop1(0,N){
	int n;
    cin >> n;
    if(num.count(n)){
		num[n]++;
    }else{
      num[n] = 1;
    }
  }
  long long count = 0;
  for(pair<long long,long long> p : num){
   long long p1 = p.first,p2 = p.second;
    if(p1 > p2){
      count += p2;
    }else if(p1 < p2){
      count += p2 - p1;
    }
  }
  cout << count << endl;
}