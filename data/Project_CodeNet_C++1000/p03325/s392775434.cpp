#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int func(int x){
 int count=0;
 while(x%2==0){
   count++;
   x/=2;
 }
return count;
}
int main() {
  int N;
  cin>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=func(a[i]);
  }
  cout<<sum<<endl;
  return 0;}