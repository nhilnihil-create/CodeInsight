#include <bits/stdc++.h>
using namespace std;

vector<pair<pair <string,int>,int>> p;
int main() {
  int N;
  cin >> N;

  for (int i =0;i<N;i++){
    string a;
    int b;
    cin>>a>>b;
    p.push_back(make_pair(make_pair(a,-b),i+1));
  }
  
  sort(p.begin(),p.end());
  
  for(int i=0;i<N;i++){
    string a;
    int b;
    cout<<p.at(i).second<<endl;
  }
}