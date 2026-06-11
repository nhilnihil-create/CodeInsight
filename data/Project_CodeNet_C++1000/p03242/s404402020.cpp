#include <iostream>

using namespace std;

int main()
{
    int a;
    int sum = 0;
    cin >> a;
    for (int i = 0 ; i < 3 ; i++){
        int y = a % 10;
        if (i == 0){
            if (y == 9){
                sum += 1;
                a /= 10;
            }else if (y == 1){
                sum += 9;
                a /= 10;
            }
        }else if (i == 1){
            if (y == 9){
                sum += 10;
                a /= 10;
            }else if (y == 1){
                sum += 90;
                a /= 10;
            }
        }else if (i == 2){
            if (y == 9){
                sum += 100;
                a /= 10;
            }else if (y == 1){
                sum += 900;
                a /= 10;
            }
        }
    }
    cout << sum;
    return 0;
}
