#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N, M;
cin>>N;

int ans=0;
vector<string> blue(N);
for(int i=0;i<N;i++)
{
  cin>>blue.at(i);
}
cin>>M;
vector<string> red(M);
for(int i=0;i<M;i++)
{
  cin>>red.at(i);
}
for(int i=0;i<N;i++)
  {
    int b=0;
  string a=blue.at(i);
  for(int j=0;j<N;j++)
    {
      if(a==blue.at(j))
      b=b+1;
      else;
    }
    for(int k=0;k<M;k++)
    {
      if(a==red.at(k))
      b=b-1;
      else;
    }
    if(b>ans)ans=b;
    else;
  }
  cout<<ans<<endl;

}