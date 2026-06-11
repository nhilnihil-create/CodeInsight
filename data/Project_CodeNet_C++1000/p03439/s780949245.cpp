#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
int N;
/* function */
int query(int x) {
    cout << x << endl;
    string ans;
    cin >> ans;
    if (ans=="Vacant")
    exit(0);
    return (ans=="Male");
}

/* main */
int main(){
    cin >> N;
    cout.flush();
    int cur;
    int left = 0, right = N - 1;
    int head = query(left), tail = query(right);
    while (1) {
        int mid = (right + left) / 2;
        cur = query(mid);
        if ( (mid - left) % 2 && head == cur || (mid - left) % 2 == 0 && head != cur ) {
            right = mid;
            tail = cur;
        }
        else {
            left = mid;
            head = cur;
        }
    }
}