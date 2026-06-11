#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int A, B, C;
    int x = 0;
    cin >> A >> B >> C;
    if(A%2 == B%2 && C%2 != B%2) {
        A++;
        B++;
        x++;
    }
    else if(A%2 == C%2 && B%2 != C%2) {
        A++;
        C++;
        x++;
    }
    else if(A%2 != B%2 && B%2 == C%2) {
        B++;
        C++;
        x++;
    }
    int a[3];
    a[0] = A;
    a[1] = B;
    a[2] = C;
    sort(a, a+3);
    x += (a[2] - a[1])/2;
    x += (a[2] - a[0])/2;
    cout << x << endl;
    return 0;
}