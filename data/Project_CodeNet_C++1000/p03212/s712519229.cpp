#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

class NBase {
    public:
        NBase(Int base, Int digits);
        void EnumAllNum();
        void EnumAllNum(vector<string>& v);
    private:
        Int m_base;
        Int m_digits; // 3から9まで
};
NBase::NBase(Int base, Int digits) : m_base(base), m_digits(digits) {
}
void NBase::EnumAllNum() {
    for (Int d = 1; d <= m_digits; ++d) {
        Int count = pow(m_base, d);
        for (Int c = 0; c < count; ++c) {
            string number = "";
            Int now = c;
            for (Int k = 0; k < d; ++k) {
                if (now == 0) {
                    number += '0';
                } else {
                    number += char((now % m_base) + '0');
                    now /= m_base;
                }
            }
            cout << number << endl;
        }
    }
    return;
}
void NBase::EnumAllNum(vector<string>& v) {
    for (Int d = 1; d <= m_digits; ++d) {
        Int count = pow(m_base, d);
        for (Int c = 0; c < count; ++c) {
            string number = "";
            Int now = c;
            for (Int k = 0; k < d; ++k) {
                if (now == 0) {
                    number += '0';
                } else {
                    number += char((now % m_base) + '0');
                    now /= m_base;
                }
            }
            v.push_back(number);
        }
    }
    return;
}

int main(void) {
    string s;
    cin >> s;
    NBase base(3, s.length());

    vector<string> v;
    base.EnumAllNum(v);

    Int answer = 0;
    Int n = stol(s);
    for (Int i = 0; i < (Int)v.size(); ++i) {
        for (Int k = 0; k < v[i].length(); ++k) {
            if (v[i][k] == '0') {
                v[i][k] = '3';
            }
            else if (v[i][k] == '1') {
                v[i][k] = '5';
            }
            else if (v[i][k] == '2') {
                v[i][k] = '7';
            }
        }
        bool a = (v[i].find('3') != string::npos && v[i].find('5') != string::npos && v[i].find('7') != string::npos);
        bool b = (n >= stoi(v[i]));
        if (a && b) {
            answer++;
        }
    }
    cout << answer << endl;
    return 0;
}
