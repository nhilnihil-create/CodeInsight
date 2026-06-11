#include <iostream>

int main() {
    int year;
    char c;
    int month;
    int day;
    std :: string heisei = "Heisei";
    std :: string tbd = "TBD";

    std :: cin >> year >> c >> month >> c >> day;
    if(year == 2019) {
        if(month <= 4){
            std :: cout << heisei << '\n';
        } else std :: cout << tbd << '\n';
    } else if(year < 2019) std :: cout << heisei << '\n';
    else std :: cout << tbd << '\n';
}