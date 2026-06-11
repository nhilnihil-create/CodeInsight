#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <utility>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <ctime>
#include <list>
#include <deque>
#include <functional>
using namespace std;
const int MAXN = 100000;
const int INF = int(1E9);
int arr[MAXN + 5], sum[MAXN + 5], temp[MAXN + 5];
long long tot1 = 0, tot2 = 0;
int N;
void MergeSort(int le, int ri) {
    if( le == ri ) return ;
    int mid = (le + ri) >> 1;
    MergeSort(le, mid);
    MergeSort(mid+1, ri);
    int p = le, q = mid+1, r = le;
    while( p <= mid && q <= ri ) {
        if( sum[p] < sum[q] ) {
            temp[r++] = sum[p++];
        }
        else {
            tot1 += (p-le);
            temp[r++] = sum[q++];
        }
    }
    while( p <= mid ) {
        temp[r++] = sum[p++];
    }
    while( q <= ri ) {
        tot1 += (p-le);
        temp[r++] = sum[q++];
    }
    for(int i=le;i<=ri;i++)
        sum[i] = temp[i];
}
bool Check(int x) {
    tot1 = 0;
    for(int i=1;i<=N;i++)
        sum[i] = (arr[i] <= x ? 1 : -1);
    for(int i=1;i<=N;i++)
        sum[i] += sum[i-1];
    MergeSort(0, N);
    return tot1 >= (tot2/2 + 1);
}
int main() {
    int le = INF, ri = -INF;
    scanf("%d", &N);
    for(int i=1;i<=N;i++) {
        scanf("%d", &arr[i]);
        le = min(le, arr[i]);
        ri = max(ri, arr[i]);
        tot2 += i;
    }
    while( le < ri ) {
        int mid = (le + ri) >> 1;
        if( Check(mid) ) ri = mid;
        else le = mid + 1;
    }
    printf("%d\n", ri);
}
