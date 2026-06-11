#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N,x;
  cin >> N >> x;
  vector<int> A(N);
  for(int i=0; i<N ; i++)
  {
    cin >> A.at(i);
  }
  sort(A.begin(),A.end());
  int B=0;
  while(1)
  {
    if(B==N)break;
    if(x-A.at(B)<0)break;
    if((B+1==N) && (x>A.at(B)))break;
    x=x-A.at(B);

    B++;
  }

  cout << B << endl;
}