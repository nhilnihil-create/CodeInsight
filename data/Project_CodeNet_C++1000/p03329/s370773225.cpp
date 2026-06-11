#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 100001
int nine[MAXN];
int six[MAXN];
int main () {
    int n;
    cin >> n;
    int min = MAXN;
    for (int i = 0; i <= n; i++) {
        int count = 0;
        int i1 = i;
        while (i1) {
            count += i1 % 9;
            i1 /= 9;
        }
        nine[i] = count;
    }
    for (int i = 0; i <= n; i++) {
        int count = 0;
        int i1 = i;
        while (i1) {
            count += i1 % 6;
            i1 /= 6;
        }
        six[i] = count;
    }
    for (int i = 0; i <= n; i++) {
        if (min > six[i] + nine[n - i]) {
            min = six[i] + nine[n - i];
        }
    }
    cout << min << endl;
    return 0;
}