#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	long long N;
 	cin >> N;
 	if(N&1)
 		cout << 2 * N << endl;
 	else
 		cout << N << endl;

    return 0;
}