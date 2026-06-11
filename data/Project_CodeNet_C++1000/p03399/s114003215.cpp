#include <bits/stdc++.h>
    
using namespace std;
typedef long long ll;
    
int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << min(A, B) + min(C, D);

    return 0;
}