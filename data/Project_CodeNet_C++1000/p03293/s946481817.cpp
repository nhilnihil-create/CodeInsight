#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t, ret = "No", ss;
    cin >>s >>t;
    for (int i = 0; i < s.size(); i++) {
        ss = "";
        for (int j = 0; j < s.size(); j++) {ss.push_back(s.at((i+j)%s.size()));}
        if (ss==t) {ret = "Yes"; break;}
    }
    cout << ret << endl;
    return 0;
}