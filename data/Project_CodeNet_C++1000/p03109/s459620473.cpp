#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s[5] == '0' && s[6] < '4'){
        cout << "Heisei";
        return 0;
    }else if (s[6] == '4'){
        if (s[8] == '2' || s[8] == '1' || s[8] == '0'){
            cout << "Heisei";
            return 0;
        }else if (s[9] == '0'){
            cout << "Heisei";
            return 0;
        }else{
            cout << "TBD";
            return 0;
        }
    }else{
        cout << "TBD";
        return 0;
    }
    return 0;
}
