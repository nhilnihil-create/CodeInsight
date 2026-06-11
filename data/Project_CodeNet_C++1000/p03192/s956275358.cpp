#include <iostream>

using namespace std;

#define endl "\n"

int main() {
    string n;
    cin >> n;

    int cnt = 0;
    for (auto i : n){
        if (i == '2') cnt++;
    }

    cout << cnt << endl;
}