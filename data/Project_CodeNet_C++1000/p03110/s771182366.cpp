#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
   double x, sum = 0;
    string u;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> u;
        sum += (u == "JPY") ? x : x * 380000.0;
    }
    cout << sum << endl;
}