#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,x;
  cin >> n >> m >> x;
  
  vector<int> vec(n + 1);
  for(int i = 0;i < n + 1;i ++){
    vec.at(i) = 1;
  }
  
  for(int i = 0;i < m;i ++){
    int kari;
    cin >> kari;
    vec.at(kari) = 2;
  }
  
  int zerocount = 0;
  
  for(int i = 0;i < x;i ++){
    if(vec.at(i) == 2)zerocount ++;
  }
  
  int saigocount = 0;
  
  for(int i = x + 1;i < n + 1;i ++){
    if(vec.at(i) == 2)saigocount ++;
  }
  
  cout << min(zerocount,saigocount) << endl;
}