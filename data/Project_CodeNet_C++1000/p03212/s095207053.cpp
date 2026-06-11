#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    string s;
    cin >> s;
    Int len = s.length();
    Int n = stol(s);
    Int answer = 0;
    for (Int i = 3; i <= len; ++i) {
        // 長さ i の準753数を列挙する
        Int kosuu = pow(3, i);
        for (Int j = 0; j < kosuu; ++j) {
            string num = "";
            Int l = j;
            for (Int k = 0; k < i; ++k) {
                if (l == 0) { 
                    num += '0';
                } else {
                    Int x = (l % 3);
                    num += char(x + '0');
                    l /= 3;
                }
            }
            for (Int k = 0; k < len; ++k) {
                if (num[k] == '0') {
                    num[k] = '3';
                }
                else if (num[k] == '1') {
                    num[k] = '5';
                }
                else if (num[k] == '2') {
                    num[k] = '7';
                }
            }
            bool a = (num.find('3') != string::npos && num.find('5') != string::npos && num.find('7') != string::npos);
            bool b = (n >= stoi(num));
            if (a && b) {
                answer++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}
