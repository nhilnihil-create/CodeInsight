#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;

    int num=1000;
    for (int i=0; i<S.length()-2; i++) {
        string sbuff;
        sbuff=S.substr(i, 3);
        int ibuff=stoi(sbuff);
        int diff=abs(753-ibuff);
        num=min(num, diff);
    }

    cout << num << endl;

    return 0;
}