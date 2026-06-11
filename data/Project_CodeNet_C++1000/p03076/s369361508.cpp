#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int a[5];
    for(int i= 0;i<5;i++) cin >>a[i];
    int sai = 10;
    int soko = 0;
    for(int i= 0;i<5;i++){
      if(a[i]%10 == 0)continue;
      if(a[i]%10 <= sai){
        sai = a[i]%10;
        soko = i;
      }
    }
    for(int i = 0;i<5;i++){
      if(i == soko) continue;
      if(a[i]%10 == 0) continue;
      a[i] += 10-a[i]%10;
    }
    int g = 0;
    for(int i= 0;i<5;i++) g+= a[i];
    cout<<g;
    
    return 0;
}