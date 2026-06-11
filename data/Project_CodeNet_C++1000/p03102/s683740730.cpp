#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n,m,c;cin>>n>>m>>c;
    int b[m];
    for(int i = 0;i<m;i++) cin>>b[i];
    int ko = 0;
    for(int i = 0;i<n;i++){
      int a[m];
      int g = 0;
      for(int j = 0;j<m;j++) cin>>a[j];
      for(int k = 0;k<m;k++){
         g+=b[k]*a[k];
      }
      if(g+c > 0) ko++;
    }
    cout<<ko;
    return 0;
}