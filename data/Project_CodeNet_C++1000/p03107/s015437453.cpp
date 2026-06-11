#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N ;
    string s ;
    cin >> s ;
    N = s.length() ;
    int red , blue ;
    red = 0 ;
    blue = 0 ;
    for(int i = 0 ; i < N ; i++){
        if(s[i] - '0' == 0) red++ ;
        else blue++ ;
    }
    cout << min(red,blue)*2 << endl;
    return 0 ;
}
