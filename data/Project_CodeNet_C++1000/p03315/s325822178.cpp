#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string s;cin>>s;
    int g = 0;
    for(int i = 0;i<4;i++){
      if(s[i] =='+') g+=1;
      else g-=1;
    }
    cout<<g;
    return 0;
}