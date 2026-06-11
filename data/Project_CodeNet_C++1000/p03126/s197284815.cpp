#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n,m;cin>>n>>m;
    int s[m];
    for(int i = 0;i<m;i++) s[i] = 0;
    for(int i = 0;i<n;i++){
      int k;cin>>k;
      for(int j = 0;j<k;j++){
        int a;cin>>a;
        a -=1;
        s[a]+=1;
      }
    }
    int ko= 0;
    for(int i = 0;i<m;i++){
      if(s[i] == n) ko++;
    }
    cout<<ko;
    return 0;
}