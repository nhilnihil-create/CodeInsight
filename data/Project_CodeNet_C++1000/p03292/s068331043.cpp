#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
  int a[3];
  int sum=0;
  for(int i=0;i<3;i++){cin>>a[i]; sum+=a[i];}
  int max_value=max({a[0],a[1],a[2]});
  int min_value=min({a[0],a[1],a[2]});
  int cen_value=sum-max_value-min_value;
  
  cout<<(cen_value-min_value)+(max_value-cen_value)<<endl;
  return 0;
}