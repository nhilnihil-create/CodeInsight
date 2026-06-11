#include <iostream>
using namespace std;

int main() {
    // 入力
    int S;
    cin >> S;

    int hyaku, ju, iti;

    hyaku = S/100;
    ju = (S/10)%10;
    iti = S%10;

    cout << hyaku + ju + iti << endl;


}