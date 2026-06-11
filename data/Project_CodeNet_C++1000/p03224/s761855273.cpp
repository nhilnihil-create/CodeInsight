#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  ll n;
  cin>>n;

  int now=1;
  
  for(int i=1;i*(i+1)<=2*n;i++){
    if(i*(i+1)==2*n){
      cout<<"Yes"<<endl;
      cout<<i+1<<endl;
      vector<int> ans[i+1];
      for(int j=0;j<=i;j++){
        for(int k=1;j+k<=i;k++){
          ans[j].push_back(now);
          ans[j+k].push_back(now);
          now++;
        }
      }
      for(int j=0;j<=i;j++){
        cout<<i<<" ";
        for(int k=0;k<i;k++) cout<<ans[j][k]<<" ";
        cout<<endl;
      }
      return 0;
    }
  }

  cout<<"No"<<endl;

  return 0;
}
