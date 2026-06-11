#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    int n , k ;
    string s = "" ;
    cin >> n >> k >> s ;
    k-- ;
    if (s[k] == 'A'){
            s[k] = 'a' ;
    }
    if (s[k] == 'B'){
            s[k] = 'b' ;
    }
    if (s[k] == 'C'){
            s[k] = 'c' ;
    }
    cout << s ;
    return 0;
}
