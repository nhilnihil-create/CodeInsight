#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
  int N;
  cin>>N;
  vector<int> a(N);
  
  for(int ni=0;ni<N;ni++)
  {
    cin>>a.at(ni);
  }
  
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  
  int Alice = 0, Bob =0;
  for(int nj=0;nj<N;nj+=2)
  {
    Alice += a.at(nj);
    if(nj+1<N)
      Bob += a.at(nj+1);
  }
  cout<<Alice-Bob<<endl;
  return 0;
}