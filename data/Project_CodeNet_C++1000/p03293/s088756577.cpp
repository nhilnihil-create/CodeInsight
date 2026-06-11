#include<string>
#include<iostream>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int i, len = s.length();
    while(i < len){
        if(s == t) {
            cout << "Yes";
            return 0;
        }
        s = s.substr(len - 1) + s.substr(0, len - 1);
        i++;
    }
    cout << "No";
    return 0;
}
