#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    for(int i = 1; i <= min(n - 1, 15000); i++){
        if((i % 3 == 0 || i % 3 == 2) && (n - i) % 2 == 0 && 6 * (n - i) - 3 <= 30000){
            for(int j = 1; j <= i; j++) cout << j * 2 << " ";
            for(int j = 1; j <= (n - i); j++) cout << j * 6 - 3 << " ";
            break;
        }
    }
    cout << endl;
}