#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    if (a <= 500 && a >= 1 && b <= 500 && b >= 1){
        if (c <= 1000){

    if (a + b >= c){
        cout << "Yes";
    }else{
        cout << "No";
    }
    }
    }
    return 0;
}
