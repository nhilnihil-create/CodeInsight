#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector <int> c(n-1);
  vector <int> s(n-1);
  vector <int> f(n-1);
  for(int i=0;i<n-1;i++)
    cin>>c.at(i)>>s.at(i)>>f.at(i);
  for(int i=0;i<n;i++){
    int t=0;
    for(int j=i;j<n-1;j++)
      t=(max(s.at(j),t)+f.at(j)-1)/f.at(j)*f.at(j)+c.at(j);
    cout<<t<<endl;
  }
}