#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int n;
  cin>>n;

  vector<double> a(n);

  double average=0;
  for(int i=0;i<n;i++){
      cin>>a.at(i);
      average+=a.at(i);
  }

  average/=(double)n;
 
 double diff_min=1000.0;
 int frame=0;
 for(int i=0;i<n;i++){
   if(diff_min > abs(a.at(i)-average))
    {
      diff_min = abs(a.at(i)-average);
      frame=i;
    }
 }
 
 cout<<frame<<endl;

	return 0;
}