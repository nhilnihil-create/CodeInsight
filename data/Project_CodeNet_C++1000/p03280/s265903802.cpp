#include <iostream>
using namespace std;


int main()
{
    int A, B;
    cin >> A >> B;
    
    int result = (A * B) - (A + B - 1);
    cout << result << endl;

    return 0;
}