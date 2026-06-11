#include <iostream>
#include <string>
using namespace std;

int main (void){
    string s;
    int n = 0;
    cin >> s; 
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '+'){
            n += 1;
        }else{
            n -= 1;
        }
    }
    cout << n << endl;
    return 0;
}
