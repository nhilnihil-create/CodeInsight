#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include <string>

#define ll long long

using namespace std;

int n;
vector<pair<int, int>> v;
int can[3001][3001];


int main() {
    int m, k;
    cin >> m >> k;

    if (m == 0) {
        if (k != 0) printf("-1");
        else printf("0 0");
        return 0;
    }
    if (m == 1) {
        if (k != 0) printf("-1");
        else printf("0 0 1 1");
        return 0;
    }

    if (k >= (1 << m)) {
        printf("-1");
        return 0;
    }

    for (int i = 0; i < (1 << m); i++) {
        if (i != k) printf("%d ", i);
    }
    printf("%d ", k);
    for (int i = (1 << m) - 1; i >= 0; i--) {
        if (i != k) printf("%d ", i);
    }
    printf("%d ", k);
}
