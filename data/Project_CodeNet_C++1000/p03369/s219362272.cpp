#include <iostream>

using namespace std;

int main()
{
    string s;
    int cost = 700;
    cin >> s;
    for (int i = 0 ; i < 3 ; i++){
        switch (s[i]){
        case 'o':
            cost += 100;
            break;
        case 'x':
            cost += 0;
            break;
        }
    }
    cout << cost;
    return 0;
}
