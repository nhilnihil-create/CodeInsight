#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,X,Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n+1,X);
  vector<int> y(m+1,Y);
  for(int i=0;i<n;i++)cin >> x.at(i);
  for(int i=0;i<m;i++)cin >> y.at(i);
  
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  
  if(x.at(n)<y.at(0)) cout << "No ";
  
  cout << "War" << endl;
}