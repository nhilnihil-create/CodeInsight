#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,B;
  cin >> A >> B;
  int num=0;
  for(int i=A; i<B+1; i++){
    int a =i/10000;
    int e =i%10;
    int b =i/1000-a*10;
    int d =(i%100-e)/10;
  if(a==e && b==d){
     num++;}
}
    cout << num <<endl;
}