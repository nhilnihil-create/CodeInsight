#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i;
  cin >> n;
  vector<pair<pair<string,int>,int>> p(n);
  for(i=0;i<n;i++){
    cin >> p.at(i).first.first >> p.at(i).first.second;
    p.at(i).first.second *= -1;
    p.at(i).second=i+1;
  }
  
  sort(p.begin(),p.end());
  for(i=0;i<n;i++){
    cout << p.at(i).second << endl;
  }
}