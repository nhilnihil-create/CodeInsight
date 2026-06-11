#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int y, m;
    y = stoi(str.substr(0,4));
    m = stoi(str.substr(5,2));
    if(y < 2019){
        cout << "Heisei" << endl;
    }else if(y > 2019){
        cout << "TBD" << endl;
    }else{
        if(m <= 4){
            cout << "Heisei" << endl;
        }else if(m > 4){
            cout << "TBD" << endl;
        }
    }
    
}