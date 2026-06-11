#include <iostream>

using namespace std;

int main (void) {
    int A, B;
    int resp;

    cin >> A >> B;
    resp = (A + B);

    if ((A - B) > resp) {
        resp = (A - B);
    }

    if ((A * B) > resp) {
        resp = (A * B);
    }

    cout << resp << endl;

    return 0;
}