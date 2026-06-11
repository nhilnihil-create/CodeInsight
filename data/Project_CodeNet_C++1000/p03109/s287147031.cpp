#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string year = s.substr(0,4);
    string month = s.substr(5,2);
    string day = s.substr(8,2);

    int yearI = stoi(year);
    int monthI = stoi(month);
    int dayI = stoi(day);

    if(yearI > 2019){
        cout << "TBD";
    }else{
        if(monthI > 4){
            cout << "TBD";
        }else{
            if(dayI > 30){
                cout << "TBD";
            }else{
                cout << "Heisei";
            }
        }
    }
}