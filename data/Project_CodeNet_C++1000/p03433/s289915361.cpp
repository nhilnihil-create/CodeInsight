#include <iostream>
#include<string>

using namespace std;
int main()
{
    int N, A;
    cin >> N >> A;

    int x = N % 500;
    string b = "No";
    if(x <= A){
        b = "Yes";
    }

    cout << b;
    return 0;
}
