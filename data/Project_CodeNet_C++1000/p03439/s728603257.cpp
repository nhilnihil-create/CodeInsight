#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int left = 0, right = N - 1;
    string ls, rs;
    cout << left << endl;
    cin >> ls;
    if(ls == "Vacant") return 0;
    cout << right << endl;
    cin >> rs;
    if(rs == "Vacant") return 0;
    while(true) {
        int mid = (left + right) / 2;
        string ms;
        cout << mid << endl;
        cin >> ms;
        if(ms == "Vacant") return 0;
        bool odd = (mid - left + 1) % 2;
        bool same = ms == ls;
        if(odd ^ same) {
            right = mid;
            rs = ms;
        }
        odd = (right - mid + 1) % 2;
        same = ms == rs;
        if(odd ^ same) {
            left = mid;
            ls = ms;
        }
    }
    return 0;
}
