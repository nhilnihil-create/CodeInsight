#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(n) cout << n << endl
using namespace std;
using ll = long long;
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string S;
    cin >> S;

    if (S[5] == '0' && S[6] - '0' <= 4) print("Heisei");
    else print("TBD");

    return 0;
}
