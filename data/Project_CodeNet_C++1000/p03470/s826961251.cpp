#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
  int N,cnt=1;
  cin>>N;
  vector<int> d(N);
  for(int ni=0;ni<N;ni++)
  {
    cin>>d.at(ni);
  }
  sort(d.begin(),d.end());
  if(N==1)
  {
    cout<<cnt<<endl;
    return 0;
  }
  for(int nj =1 ;nj<N;nj++)
  {
    if(d.at(nj-1)!=d.at(nj))
      cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}