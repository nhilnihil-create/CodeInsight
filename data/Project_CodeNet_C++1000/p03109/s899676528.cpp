#include <iostream>
using namespace std;
int main(void){
    int y,m;
    char c;
    cin >> y >> c >> m;
    if(y<=2019 && m<=4) cout << "Heisei";
    else cout << "TBD";
}