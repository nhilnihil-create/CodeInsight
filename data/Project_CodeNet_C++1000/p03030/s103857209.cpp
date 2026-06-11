#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  pair<pair<string,int>,int> p[120];
  for(int i=0;i<n;i++){
    string s;
    int k;
    cin >> s >> k;
    p[i]=make_pair(make_pair(s,-k),i+1);
  }
  sort(p,p+n);
  for(int i=0;i<n;i++){
    cout << p[i].second << endl;
  }
}