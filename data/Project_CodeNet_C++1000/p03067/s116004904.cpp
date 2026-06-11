#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if((B <= A) && (B <= C) && (C <= A)) {
        cout << "Yes" << endl;
    } else if((B >= A) && (B >= C) && (C >= A)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    //
    // B, C, A or A, C, B
    return 0;
}