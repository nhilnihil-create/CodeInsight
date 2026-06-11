#include <iostream>
#include <string>
using namespace std;
int main(void){
    
    string S;
    cin >> S;
    
    string year = S.substr(0, 4);
    string month = S.substr(5, 5);

    if(year <= "2019"){
        if(month <= "04/30"){
            cout << "Heisei" << endl;
        }
        else{
            cout << "TBD" << endl;
        }
    }
    else{
        cout << "TBD" << endl;
    }  
}
