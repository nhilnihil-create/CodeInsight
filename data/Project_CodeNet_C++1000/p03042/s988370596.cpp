#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int fst = stoi(str.substr(0,2));
    int scd = stoi(str.substr(2,2));
    
    if(1 <= fst && fst <= 12){
        if(1 <= scd && scd <= 12){
            cout << "AMBIGUOUS" << endl;
        }else{
            cout << "MMYY" << endl;
        }
    }else{
        if(1 <= scd && scd <= 12){
            cout << "YYMM" << endl;
        }else{
            cout << "NA" << endl;
        }
    }
}