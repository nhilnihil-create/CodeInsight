#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> L(87);
  L.at(0)=2;
  L.at(1) = 1;
    for(int i=0; i< 87; i++){
    if(i == 0 || i == 1) continue;
    else{
      L.at(i) = L.at(i-1)+L.at(i-2);
    }
  }
 cout << L.at(n) << endl;
  

}
