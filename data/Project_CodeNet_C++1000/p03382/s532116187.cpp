#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    auto vmax = *max_element(A.begin(), A.end());

    auto res = *min_element(A.begin(), A.end(),
        [&](int a, int b){
            auto a2 = a != vmax? abs(2 * a - vmax) : INT_MAX;
            auto b2 = b != vmax? abs(2 * b - vmax) : INT_MAX;
            return a2 < b2;
        });
    cout<<vmax<<" "<<res<<endl;

    return 0;
}