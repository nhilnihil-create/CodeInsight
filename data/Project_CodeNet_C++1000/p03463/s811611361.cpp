#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int vac = abs(B - A) - 1;

    if(vac % 2 == 0) cout << "Borys" << endl;
    else cout << "Alice" << endl;

    return 0;
}