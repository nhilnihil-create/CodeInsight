#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num=0;
 	 cin>>num;
  int sum=0;
  int max=0;
  vector<int> goods(num);
  for(int i=0;i<num;i++){
    cin>>goods.at(i);
    sum+=goods.at(i);
    if(goods.at(i)>max)max=goods.at(i);
  }
  cout<<sum-max/2<<endl;
}