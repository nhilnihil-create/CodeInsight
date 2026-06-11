#include <iostream>

int main()
{
  using namespace std;
  int A,B,C;
  cin>>A>>B>>C;
  cout<<B+(A+B+1<C?A+B+1:C)<<endl;
}