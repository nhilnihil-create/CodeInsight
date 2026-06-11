#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin >> s;
    string y = s.substr(0,4);
    string m = s.substr(5,2);
    int ny = stoi(y);
    int nm = stoi(m); 
    if(ny <= 2018 || ny == 2019 && nm < 5) puts("Heisei");
    else puts("TBD");
    return 0;
}