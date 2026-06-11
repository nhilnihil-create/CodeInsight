#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int check_text (string s, char x) ;
int main() {
    int a , t = 0 ;
    string text , smal;
    char x ;
    smal = "abc" ;
    cin >> text ;
    for(int i = 0 ; i < 3 ; i++){
        x = smal[i] ;
        t += check_text (text,x) ;
    }
    if ( t == 3 ) {
        cout << "Yes" ;
    }
    else {
        cout << "No" ;
    }
    return 0 ;
}

int check_text (string s, char x){
    for(int i = 0 ; i < 3 ; i++){
        if(s[i] == x){
            return 1;
        }
  }
        return 0;
}
