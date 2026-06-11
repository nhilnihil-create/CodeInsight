#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int n,k;
  cin >>n >>k;
  int count=0;
  while(n>0){
    if(count==0){n-=k;count++;continue;}
    n-=k-1;
    count++;
  }
  cout << count << endl;
}