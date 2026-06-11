#include <bits/stdc++.h>
using namespace std;

int main()
{

        int A, B;
        cin >> A >> B;

        int ans = A * B;

        for (int i = 0; i < 3; ++i) {

                int tmp = ans * (i+1);
                if (ans % 2) {
                        cout << "Yes" << endl;
                        exit(0);
                }

        }
        cout << "No" << endl;

}
