#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string a;cin>>a;
    for(int i = 0;i<a.length();i++){
      if(a[i] == '1') cout<<"9";
      else cout<<"1";
    }
    return 0;
}