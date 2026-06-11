#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a;
    int b;
    int c;
    int d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    int result = min(a, b) + min(c, d);
    cout << result << endl;
}