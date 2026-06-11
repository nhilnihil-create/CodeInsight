#include <iostream>

using namespace std;

int main()
{
    int n ,a ,b;
    cin >> n >> a >> b;
    int result;
    if (n*a > b ){
        result =b;
    }
    else {
        result =n*a;
    }
    cout << result;
    return 0;
}
