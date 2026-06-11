#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    double n;cin>>n;
    double t,a;cin>>t>>a;
    double ss = 1000000000;
    int ans = 0;
    for(int i = 1;i<=n;i++){
      double h;cin>>h;
      double k = t-h*0.006;
      double sa = abs(k-a);
      if(ss >= sa){
        ss = sa;
        ans = i;
      }
    }
    cout<<ans;
    return 0;
}