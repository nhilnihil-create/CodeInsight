#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int max_turn = INT_MAX;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        int counter = 0;
        while(num % 2 == 0) {
            num = num / 2;
            ++counter;
        }

        max_turn = min(max_turn, counter);
    }

    cout << max_turn << endl;
}