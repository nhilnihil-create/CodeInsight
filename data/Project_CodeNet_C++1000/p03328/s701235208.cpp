#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A,B;
    cin >> A >> B;
    int x = B - A;
    int sum = (x-1)*x/2;
    cout << sum - A << endl;
    return 0;
}