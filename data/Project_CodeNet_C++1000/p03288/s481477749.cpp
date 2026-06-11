#include<bits/stdc++.h>
using namespace std;
#define rep(i,s, n) for(int i = s; i < (int)(n); i++)
#define co(x) cout<<x<<endl
#define SQvec(i,j) vector<vector<int>> data(i, vector<int>(j))
#define mod 1000000000+7
typedef long long int lint;

int main (){
  int R;
  cin >> R;
  if(R < 1200){co("ABC");}
  else if(R < 2800){co("ARC");}
  else{co("AGC");}
  return 0;
}