#include <iostream>

using namespace std;

int main()
{
    string s;
    int sum = 0;
    cin >> s;
    for (int i = 1 ; i <= 4 ; i++){
        switch (s[i - 1]){
            case '+':
                sum++;
                break;
            case '-':
                sum--;
                break;
        }
    }
    cout << sum;
    return 0;
}
