#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int harf;
    int cnt = 0;
    int cnt2 = 0;
    int tmpMax = 0;
    int maxKi;
    int maxGu;
    map<int, int> mKi;
    map<int, int> mGu;

    cin >> num;

    vector<int> vec(num);
    for (int i = 0; i < num; i++) cin >> vec.at(i);

    harf = num / 2;

    for (int i = 0; i < num; i += 2) mKi[vec.at(i)]++;
    for (int i = 1; i < num; i += 2) mGu[vec.at(i)]++;

    for (auto itr : mKi) {
        if (itr.second > tmpMax) {
            tmpMax = itr.second;
            maxKi = itr.first;
        }
    }
    cnt = harf - tmpMax;

    tmpMax = 0;
    for (auto itr : mGu) {
        if (itr.first == maxKi) continue;
        tmpMax = max(itr.second, tmpMax);
    }
    cnt += harf - tmpMax;

    tmpMax = 0;
    for (auto itr : mGu) {
        if (itr.second > tmpMax) {
            tmpMax = itr.second;
            maxGu = itr.first;
        }
    }
    cnt2 = harf - tmpMax;

    tmpMax = 0;
    for (auto itr : mKi) {
        if (itr.first == maxGu) continue;
        tmpMax = max(itr.second, tmpMax);
    }
    cnt2 += harf - tmpMax;

    cout << min(cnt,cnt2);

    //
}
