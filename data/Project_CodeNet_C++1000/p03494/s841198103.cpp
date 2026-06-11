#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n,a,i,j,res=50;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a;
    j=0;
    while(a%2==0&&j<res){
      a/=2;
      j++;
    }
    res=min(res,j);
  }
  cout << res << endl;
  return 0;
}