#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int n;
array<int, 50> d;

int calc(array<bool, 25>& arr, int i) {
    if(i == n) {
        int a = -24, min = 24;
        rep(k, 25) {
            if(arr[k]) {
                if(min > k - a) min = k - a;
                a = k;
            }
        }
        return min;
    } else {
        int x = 0, y = 0;
        if(!arr[d[i]]) {
            arr[d[i]] = true;
            x = calc(arr, i + 1);
            arr[d[i]] = false;
        }

        if(!arr[24-d[i]]) {
            arr[24-d[i]] = true;
            y = calc(arr, i + 1);
            arr[24-d[i]] = false;
        }

        if(x < y) x = y;
        return x;
    }
}

int main() {
    cin >> n;
    rep(i, n) cin >> d[i];
    array<bool, 25> arr;
    fill(arr.begin(), arr.end(), false);
    arr[0] = arr[24] = true;
    cout << calc(arr, 0) << endl;
}