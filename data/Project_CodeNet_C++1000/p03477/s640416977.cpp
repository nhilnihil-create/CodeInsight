#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
    
int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int left = A + B;
    int right = C + D;
    if (left > right) {
        cout << "Left";
    } else if (left == right) {
        cout << "Balanced";
    } else {
        cout << "Right";
    }

    return 0;
}
