#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  int a,b;
  cin >> a >> b;
  string s;
  cin >>s;
  bool c=false;
  bool d=true;
  if(s.size()==a+b+1)c=true;
  rep(i,s.size()){
      if(i==a && s.at(i)!='-'){
          d=false;
          break;
      }
      else if(i!=a && s.at(i)=='-'){
          d=false;
          break;
      }
  }
  if(c && d)cout << "Yes"<< endl;
  else cout << "No"<< endl;  
}