#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  double t,a;
  cin >>n>>t>>a;
  vector<double>x(n);
  for(int i=0;i<n;i++)cin>>x[i];
  double sa=1e18;
  int bango=0;
  for(int i=0;i<n;i++){
    double kion=a-(t-0.006*x[i]);
    if (kion<0)kion*=-1;
    //cout<<kion<<endl;
    if(sa>kion){
      sa=kion;
      bango=i+1;
    }
  }
  cout<<bango<<endl;
  return 0;
}