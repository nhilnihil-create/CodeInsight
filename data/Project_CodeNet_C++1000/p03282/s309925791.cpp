#include <iostream>

using namespace std;
int main(void){
    string s;
    long long k;
    cin >> s;
    cin >> k;
    
    long t = 0;
    char c = '1';
    for(long i = 0;i < s.size();i++){
          if(s[i] == '1'){
                t++;
          }else{
                c = s[i];
                break;
          }
    }
    if(t >= k){
          cout << '1' << endl;
    }else{
          cout << c << endl;
    }
}
