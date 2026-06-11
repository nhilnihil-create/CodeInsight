#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main(void) {
    string date = "2019/04/30";
    string s;
    cin >> s;
    if(s <= date){
        cout << "Heisei" << endl;
    }else{
        cout << "TBD" << endl;
    }
    return 0;
}
