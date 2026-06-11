#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
  vector<VI> c(3,VI(3));
  rep(i,3){
    rep(j,3){
      cin >> c.at(i).at(j);
    }
  }
  vector<int> v={0,1,2};
  sort(v.begin(),v.end());
  int m=c.at(0).at(0)+c.at(1).at(1)+c.at(2).at(2);
  int n;
  bool a=true;
  do{
    n=c.at(0).at(v.at(0))+c.at(1).at(v.at(1))+c.at(2).at(v.at(2));
    if(n!=m){
		a=false;
      break;
    }
    }while (next_permutation(v.begin(), v.end()));
  if(a) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}