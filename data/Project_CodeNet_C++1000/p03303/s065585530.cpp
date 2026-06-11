#include <bits/stdc++.h>
using namespace std;
 
int main() {
string s;
  int w;
cin>>s;
  int q=s.size();
  string k;
  cin>>w;
  for(int i=0;i<q;i +=w){
  k =k+ s[i];
  
  }
  cout << k <<endl;
}
