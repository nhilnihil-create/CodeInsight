#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
 string s;
  cin >>s;
  int num=s.size();
  int c=s.at(0)-48;
  bool a=true;
  for(int i=1;i<num;i++){
    if(s.at(i)!='9') a=false;
  }
  if(a) cout << c+9*(num-1) <<endl;
  else cout << c-1+9*(num-1) <<endl;
    
  
}
  