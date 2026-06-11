#include <bits/stdc++.h>
using namespace std;


int main() {

  int n;
  cin>>n;

  int t,a;
  cin>>t>>a;

  long double min_wk=10000000000;
  int point;
  for(int i=0;i<n;i++){
    int h;
    cin>>h;

    long double temp = abs(t-h*0.006-a);
  
    if(temp<min_wk)
    {
      min_wk=temp;
      point=i+1;
    }
  }

  cout<<point<<endl;

  return 0;
}


