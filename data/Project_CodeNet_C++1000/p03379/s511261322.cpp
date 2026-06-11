#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N;
    cin >> N;
    vector<int64_t>vec(N);
    vector<int64_t>vec2(N);
    for (int i=0; i<N; i++) {
        cin >> vec.at(i);
        vec2[i] = vec[i];
    }

    sort(vec.begin(), vec.end(), greater<int64_t>());
    int64_t medium = N / 2;
    for (int64_t i=0; i<N; i++) {
        int64_t num = vec2[i];
        if (num >= vec[medium-1]) {
            cout << vec[medium] << endl;
        } else {
            cout << vec[medium-1] << endl;
        }
    }
    return 0;
}