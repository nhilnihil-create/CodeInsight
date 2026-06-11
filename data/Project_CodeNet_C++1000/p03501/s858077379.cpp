#include <iostream>

using namespace std;

int main (void) {
    int N, A, B;
    cin >> N >> A >> B;

    int plan1 = A * N;
    int plan2 = B;
    if ( plan1 < plan2 )
        cout << plan1;
    else
        cout << plan2;
    cout << endl;
}
