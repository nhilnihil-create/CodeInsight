#include <bits/stdc++.h>
using namespace std;


int main() {

  int n,m,x,y;
  cin>>n>>m>>x>>y;

  vector<int> xi(n);
  for(int i=0;i<n;i++){
    cin>>xi.at(i);
  }

  vector<int> yi(m);
  for(int i=0;i<m;i++){
    cin>>yi.at(i);
  }

  sort(xi.begin(),xi.end());
  sort(yi.begin(),yi.end());

  if(xi.at(n-1)<yi.at(0)&&x<yi.at(0)&&y>xi.at(n-1))
    cout<<"No War"<<endl;
  else
    cout<<"War"<<endl;

    return 0;
}