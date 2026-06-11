#include <bits/stdc++.h>
using namespace std;

int main()
{

        int A = 0;
        int B = 0;
        int C = 0;
        int D = 0;

        cin >> A;
        cin >> B;

        cin >> C;
        cin >> D;

        int total = 0;

        if (A > B) {
                total = B;
        }
        else {
                total = A;
        }
        if (C > D) {
                total += D;
        }
        else {
                total += C;
        }
        cout << total << endl;


}
