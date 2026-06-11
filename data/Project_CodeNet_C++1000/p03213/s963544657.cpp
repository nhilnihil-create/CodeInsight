#include <bits/stdc++.h>
#include <tuple>
typedef long long int ll;
using namespace std;
int main() {
    int primelist[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int num_of_prime[15];
    int n;
    cin >> n;
    for (int i = 0; i < 15; i++) {
        int n1 = n;
        int count = 0;
        while (n1) {
            n1 /= primelist[i];
            count += n1;
        }
        num_of_prime[i] = count;
    }
    int ret = 0;
    for (int i = 0; i < 15; i++) {
        if (num_of_prime[i] >= 74) {
            ret++;
        }
    }
    //cout << num_of_prime[2] << endl;
    int p1 = 0;
    int q1 = 0;
    for (int i = 0; i < 15; i++) {
        if (num_of_prime[i] >= 24) {
            p1++;
            q1++;
        }
        else if (num_of_prime[i] >= 2) {
            q1++;
        }
    }
    ret += p1 * (q1 - 1);
    int p2 = 0;
    int q2 = 0;
    for (int i = 0; i < 15; i++) {
        if (num_of_prime[i] >= 14) {
            p2++;
            q2++;
        }
        else if (num_of_prime[i] >= 4) {
            q2++;
        }
    }
    ret += p2 * (q2 - 1);
    int p3 = 0;
    int r3 = 0;
    for (int i = 0; i < 15; i++) {
        if (num_of_prime[i] >= 4) {
            p3++;
            r3++;
        }
        else if (num_of_prime[i] >= 2) {
            r3++;
        }
    }
    ret += p3 * (p3 - 1) / 2 * (r3 - 2);
    cout << ret << endl;
    return 0;
}