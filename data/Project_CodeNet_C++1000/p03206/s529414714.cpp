#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int D;
    cin >> D;

    map<int , string> dict{
        {22, "Christmas Eve Eve Eve"},
        {23, "Christmas Eve Eve"},
        {24, "Christmas Eve"},
        {25, "Christmas"}};

    cout << dict[D] << endl;
}