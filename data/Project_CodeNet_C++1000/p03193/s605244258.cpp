#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int n,h,w;
  std::cin>>n>>h>>w;
  vector <int> a;
  vector <int> b;
  int i,count=0;
  int input;
  for(i=0;i<n;i++)
  {
    std::cin>>input;
    a.push_back(input);
    std::cin>>input;
    b.push_back(input);
    if(a[i]>=h&&b[i]>=w)
      count+=1;
  }
  std::cout<<count;
  return 0;
}