#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int64_t n; cin >> n;
    vector<int64_t> lucas(n + 1);
    lucas.at(0) = 2; lucas.at(1) = 1;

    for(int i = 0; i < n-1; i++){
        lucas.at(i + 2) = lucas.at(i) + lucas.at(i + 1);
    }
    printf("%ld\n", lucas.at(n));
}