#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int sum=a+b+c;
  int max_sum=max(a,max(b,c))*3;
  if((max_sum-sum)%2==0)cout << (max_sum-sum)/2 << endl;
  else cout << 2+(max_sum-sum)/2 << endl;
}