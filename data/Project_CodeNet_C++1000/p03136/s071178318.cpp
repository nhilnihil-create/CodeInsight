#include <iostream>
#include <climits>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a;
  int max = INT_MIN;
  int total = 0;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    total+=a;
    if(a>max)
      max=a;
  }	
  if(total-max>max)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}
