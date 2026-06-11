#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main(void) {
    string n;
    cin >> n;
    for(int i = 0; i < n.length(); i++){
        if(n[i] == '1'){
            n[i] = '9';
        }else{
            n[i] ='1';
            
        }
    }
    cout << n[0] << n[1] << n[2] << endl;
    return 0;
}