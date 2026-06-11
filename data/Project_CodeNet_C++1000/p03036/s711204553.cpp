#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int r,D,st;
  cin >> r >> D >> st;
  
  long long int ne = st;
  for(long long int i=0;i<10;i++){
     ne =  (ne*r)-D;
     cout << ne << endl;;
  }
}
