#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> N(4),v={1,4,7,9};
  for(int &i:N)
    cin>>i;
  sort(N.begin(),N.end());
  if(N==v)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}