#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,B,C;
  cin>>A>>B>>C;
  if(A>B&&(A>C&&B<C)) cout<<"Yes"<<endl;
  else if(A<B&&(A<C&&B>C)) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
