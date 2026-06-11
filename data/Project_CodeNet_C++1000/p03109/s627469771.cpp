#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    string tmp;
    vector <int> ymd(3);
    int id = 0;

    cin >> s;

    for(int i = 0; i < s.size(); i++) {

        if(s[i] == '/') {
            ymd[id] = atoi(tmp.c_str());
            id ++;
            tmp = "";
            continue;
        }

        tmp += s[i];
    }

    ymd[id] = atoi(tmp.c_str());

    if(ymd[1] > 4) {
        cout << "TBD" << endl;
    } else {
        cout << "Heisei" << endl;
    }

    //cout << s << endl;

}