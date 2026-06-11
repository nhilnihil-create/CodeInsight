#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> x(n);
  for(int i=0;i<n;i++)
    cin>>x.at(i);
  vector<int> s=x;
  sort(s.begin(),s.end());
  for(int i=0;i<n;i++)
    cout<<(x.at(i)<s.at(n/2)?s.at(n/2):s.at(n/2-1))<<endl;
}