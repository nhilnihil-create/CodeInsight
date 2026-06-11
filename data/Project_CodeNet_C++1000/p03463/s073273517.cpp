#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, A, B;
    cin >> n >> a >> b;

    A = min(a,b);
    B = max(a,b);

    if((B-A-1) % 2){
        cout << "Alice" << endl;
    } else {
        cout << "Borys" << endl;
    }
    
}