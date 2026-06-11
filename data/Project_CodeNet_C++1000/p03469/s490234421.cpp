#include <iostream>
using namespace std;

int main(void) {
    string S;cin>>S;
    string date = S.substr(8, 2);
    cout << "2018/01/" << date << endl;
    return 0;
}