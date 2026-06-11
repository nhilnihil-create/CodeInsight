#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <complex>
typedef long long int LL;
using namespace std;

// 插入此處

int main() {
    int n;
    scanf("%d", &n);
    if (n < 1200) {
        printf("ABC\n");
    } else if (n < 2800) {
        printf("ARC\n");
    } else {
        printf("AGC\n");
    }
}
