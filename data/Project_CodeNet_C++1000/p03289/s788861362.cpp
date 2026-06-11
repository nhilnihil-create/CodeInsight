#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



int main(void){
    string s;
    cin >> s;
    int c = 0;
    for(int i = 2;i < s.size() - 1;i++){
          if(s[i] == 'C')c++;
    }
    
    if(s[0] == 'A' && c == 1){
          for(int i = 1;i < s.size();i++){
                if(s[i] == 'C')continue;
                if(!('a' <= s[i] && s[i] <= 'z')){
                      cout << "WA" << endl;
                      return 0;
                }
          }
          cout << "AC" << endl;
    }else{
          cout << "WA" << endl;
    }
    
    
}
