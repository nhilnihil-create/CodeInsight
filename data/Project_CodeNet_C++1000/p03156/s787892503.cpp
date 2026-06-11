#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,n,a,b,p,x=0,y=0,z=0;
  cin >> n >> a >> b;
  for(i=0;i<n;i++){
    cin >> p;
    if(p<=a){
      x++;
    }
    else if(p<=b){
      y++;
    }
    else{
      z++;
    }
  }
  cout << min(x,min(y,z)) << endl;;
  return 0;
}