#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll; //long longをllとして簡略
 
int main(){
  int a[5]={0};
  rep(i,6){
    int z;
    cin >>z;
    a[z]++;
  }
  if(a[1]<=2&&a[2]<=2&&a[3]<=2&&a[4]<=2){
    cout << "YES" <<endl;
    return 0;
  }
  cout << "NO" <<endl;
  return 0;
}