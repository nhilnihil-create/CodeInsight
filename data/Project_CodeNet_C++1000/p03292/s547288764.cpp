#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v;
  int a;
  for(int i =0; i<3; i++)
  {
    cin>>a;
    v.push_back(a);
  }
  int sum = 0;
  sort(v.begin(), v.end());
  for(int i = 0; i<2; i++)
  {
    sum = sum + (v[i+1] - v[i]);
  }
  cout<<sum;
  return 0;
}