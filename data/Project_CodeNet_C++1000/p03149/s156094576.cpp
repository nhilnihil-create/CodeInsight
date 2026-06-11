#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int>a(4);
  for(int i=0;i<4;i++){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  cout <<(a.at(0) == 1&&a.at(1)==4&&a.at(2)==7&&a.at(3)==9?"YES":"NO")<<endl;
}

