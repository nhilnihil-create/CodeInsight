#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int A, B, C;
    std::cin >> A >> B >> C;
    int g = max<int>({ A * 10 + B + C,A + B * 10 + C,A + B + C * 10 });
    cout << g << endl;
}
