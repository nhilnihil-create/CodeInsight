#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,sum;
  sum=0;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
    sum+=a.at(i);
  }
  cout<<sum-n<<endl;
}