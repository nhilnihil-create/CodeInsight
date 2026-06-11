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
    string S;
    cin >> S;
    map<char, int>d;
    for (int i=0; i<N; i++) {
        if (d.count(S[i]) > 0) {
            d[S[i]] = d[S[i]] + 1;
        } else {
            d[S[i]] = 1;
        }
    }

    int a_count = 0;
    for (auto s : d) {
        a_count++;
    }

    int b_count = 0;
    int max_count = 0;
    for (int i=1; i<N; i++) {
        map<char, int> s;
        int count = 0;
        d[S[i-1]] -= 1;
        for (int j=0; j<i; j++) {
            if (s.count(S[j]) > 0) {
                s[S[j]] += 1;
            } else {
                s[S[j]] = 1;
            }
        }

        for (auto b : d) {
            if (b.second > 0 && s.count(b.first) > 0) {
                count += 1;
            }
        }

        if (count > max_count) {
            max_count = count;
        }
    }

    cout << max_count << endl;
    return 0;
}