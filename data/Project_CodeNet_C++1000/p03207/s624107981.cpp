//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;

#define endl "\n"

const int MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    int a, sum = 0;
    cin >> a;
    int ara[a];
    for(int i = 0 ; i < a; i++){ cin >> ara[i];}

    sort(ara,ara+a);
    for(int i = 0 ; i < (a-1); i++){
        sum += ara[i];

    }
    cout << sum + (ara[a-1]/2) << endl;


    return 0;
}
