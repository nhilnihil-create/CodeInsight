#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int A1, A2, A3;
    std::cin >> A1 >> A2 >> A3;
    int x = max({ A1, A2, A3 }) - min({ A1,A2,A3 });
    cout << x << endl;
}
