#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int sum = 0;
    cin >> a >> b;
    for (int i = 1 ; i <= 3 ; i++){
        if ((a * b * i) % 2 == 1){
            sum++;
        }
    }
    if (sum > 0){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}
