#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
  int n1,n2;
  cin >>n1 >>n2;
  int diff=n2-n1;
  ll sum=0;
  rep(i,diff){
    sum+=i;
  }
  cout << sum-n1 << endl;
}