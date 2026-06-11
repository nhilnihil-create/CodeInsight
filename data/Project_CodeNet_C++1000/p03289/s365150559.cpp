#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rept(i,s,n) for (int i = (s); i < (n); ++i)

#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;

int main() {

  string s;
  cin >> s;
    
    bool ok = true;
    
    if(s.at(0)!='A'){
        ok = false;
    }
    
    int cCount = 0;
    int cIdx = -1;
    int i;
    for(i=2; i<=s.length()-2; ++i){
        if(s.at(i)=='C'){
            cCount++;
            cIdx = i;
        }
    }
    if(cCount!=1){
        ok = false;
    }
    
    for(i=1;i<s.length();++i){
        if(i!=cIdx){
            if(s.at(i)<97 || s.at(i) >122){
                ok = false;
            }
        }
    }
    
    
    if(ok)
        cout << "AC" << endl;
    else
        cout << "WA" << endl;
    
    
  
  return 0;
}
