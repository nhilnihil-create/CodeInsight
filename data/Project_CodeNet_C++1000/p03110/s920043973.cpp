#include<iostream>
using namespace std;

int main() {
    int n;
    float x, sum;
    string u;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> u;
        if (u == "JPY") sum += x;
        else sum += 380000 * x;
    }

    cout << sum << endl;
    
}