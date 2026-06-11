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
    vector<pair<string, int>>vec(N);
    for (int i=0; i<N; i++) {
        string s;
        int n;
        cin >> s >> n;
        vec[i] = make_pair(s, -1*n);
    }

    vector<pair<string, int>>orig(N);
    copy(vec.begin(), vec.end(), orig.begin());
    sort(vec.begin(), vec.end());

    for (int i=0; i<N; i++) {
        string s = vec[i].first;
        int num = vec[i].second;
        for (int j=0; j<N; j++) {
            if (s == orig[j].first && num == orig[j].second) {
                cout << j + 1 << endl;
            }
        }
    }
    return 0;
}