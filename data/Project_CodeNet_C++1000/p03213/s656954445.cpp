#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main(void){
  int n,a,i,l,k[30]={};
  vector<int> p;
  
  cin >> n;
  
  for (a=2;a<=n;a++){
    for (i=0;i<p.size();i++){
      if (a%p[i]==0) break;
    }
    if (i==p.size()) p.push_back(a);
  }
  
  for (a=2;a<=n;a++){
    l=a;
    while (l>1){
      for (i=0;i<p.size();i++){
        while (l%p[i]==0){
          k[i]++;
          l/=p[i];
        }
      }
    }
  }
  
  int y2,y4,y14,y24,y74;
  y2=y4=y14=y24=y74=0;
  for (i=0;i<p.size();i++){
    if (k[i]>=74) y74++;
    if (k[i]>=24) y24++;
    if (k[i]>=14) y14++;
    if (k[i]>=4) y4++;
    if (k[i]>=2) y2++;
  }
  
  int ans=0;
  ans+=y74;
  ans+=y24*(y2-1);
  ans+=y14*(y4-1);
  ans+=y4*(y4-1)/2*(y2-2);
  
  cout << ans << endl;
  
  return 0;
}