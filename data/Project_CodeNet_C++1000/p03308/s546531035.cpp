#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;
    vector<long long> vec(N);
    
    for (auto i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    
    
    cout << vec[N-1] - vec[0] << endl;
}
