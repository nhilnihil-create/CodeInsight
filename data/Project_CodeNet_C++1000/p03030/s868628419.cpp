#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<string,pair<int,int>>> c(n);
  for(int i = 0; i < n; i++){
    string s;
    int a;
    cin >> s >> a;
    c[i].first = s;
    c[i].second.first = -a;
    c[i].second.second = i+1;
  }
  sort(c.begin(),c.end());
  for(int i = 0; i < n; i++){
    cout << c[i].second.second << endl;
  }
}