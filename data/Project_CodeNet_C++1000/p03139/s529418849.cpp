#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll; //long longをllとして簡略
 
int main(){
  int ans=0;
  int n,a,b;
  cin >> n >> a >> b;
  int temp =  (a+b)-n;
  if(temp<0){temp=0;}
  cout << a+b-max(a,b) <<" " << temp <<endl;
  return 0;
}