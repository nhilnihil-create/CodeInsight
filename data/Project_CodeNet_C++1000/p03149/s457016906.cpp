#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;
int main(){
  vector<int> v(4,0);
    r(i,4) cin>>v.at(i);
  sort(v.begin(),v.end());
  if(v[0]==1&&v[1]==4&&v[2]==7&&v[3]==9)cout << "YES"<<endl;
  else cout <<"NO"<<endl;
}