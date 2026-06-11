#pragma GCC optimize ("O3")
#pragma GCC target ("sse4") // wonderful

#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);


    int r, d, x;
    cin >> r >> d >> x;

    for (int i = 0; i < 10; i++) {

        x = x * r - d; 
        cout << x  << "\n";

    }

    return 0;


}
