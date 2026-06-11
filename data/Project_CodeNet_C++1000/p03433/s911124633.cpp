#include <iostream>

using namespace std;

int main()
{
    int N , A , C;
    cin >> N >> A;
    C = (N % 500) - A;

    if(C <= 0) {cout << "Yes";}
    else {cout << "No";}
}
