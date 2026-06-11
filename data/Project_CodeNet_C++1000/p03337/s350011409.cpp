#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int max = 0;
    cin >> a >> b;
    if (a + b >= a - b){
        max = a + b;
        if (a + b >= a * b){
            max = a + b;
        }else{
            max = a * b;
        }
    }else if (a - b >= a * b){
        max = a - b;
    }else{
        max = a * b;
    }
    cout << max;
    return 0;
}
