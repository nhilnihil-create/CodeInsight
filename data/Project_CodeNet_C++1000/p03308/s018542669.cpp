#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> vec(N);
    for (int i = 0; i < N; ++i)
        cin >> vec[i];
    long long dif = *max_element(vec.begin(), vec.end()) - *min_element(vec.begin(), vec.end());
    cout << dif << "\n";
}