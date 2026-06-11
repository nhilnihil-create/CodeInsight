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
    vector<int>vec(N);
    for (int i=0; i<N; i++) {
        cin >> vec.at(i);
    }

    int sum_count = 0;
    bool can_mizuyari = true;
    while (can_mizuyari) {
        int count = 0;
        bool mizuyari = false;
        for (int i=0; i<N; i++) {
            if (mizuyari && vec[i] == 0) {
                count += 1;
                mizuyari = false;
            } else if (vec[i] != 0) {
                vec[i] = vec[i] -1;
                mizuyari = true;
            }
        }

        if (mizuyari)  {
            count += 1;
        }

        if (count == 0) {
            can_mizuyari = false;
        }

        sum_count += count;
    }

    cout << sum_count << endl;
    return 0;
}