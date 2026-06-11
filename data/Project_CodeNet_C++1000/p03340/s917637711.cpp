#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int64_t N;
    cin >> N;
    vector<int64_t>vec(N);
    for (int i=0; i < N; i++) {
        cin >> vec.at(i);
    }

    int right = 0;
    int64_t sum = 0;
    int64_t count = 0;
    for (int left=0; left < N; left++) {
        while(right < N && (sum ^ vec[right]) == (sum + vec[right])) {
            sum += vec[right];
            right++;
        }

        count += right - left;
        if (left == right) {
            right++;
        }
        sum -= vec[left];
    }

    cout << count << endl;
    return 0;
}