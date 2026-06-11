#include <iostream>
using namespace std;
int main(void){
    string s;
    cin >> s;
    if(s.length() == 3){
        swap(s.at(0), s.at(2));
    }
    cout << s << endl;
    return 0;
}