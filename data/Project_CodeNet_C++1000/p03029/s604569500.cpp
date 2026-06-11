# include<bits/stdc++.h>
using namespace std;
int main(){
  int A,P,q,x,total;
  cin>>A>>P;
  total = 3*A + P;
  q = total % 2;
  x = (total-q) /2;
  cout << x <<endl;
}