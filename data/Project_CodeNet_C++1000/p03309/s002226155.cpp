#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int N; vector<int> A;
void input()
{
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
}

void solve()
{
    int pl = 0,mi = 0,zr = 0;
    for (int i = 0; i < N; ++i){
        A[i] -= i+1;
        if (A[i] > 0) ++pl;
        else if (A[i] < 0) ++mi;
        else ++zr;
    }
    
    if (mi > pl){
        for (int i = 0; i < N; ++i) A[i] = -A[i];
        swap (pl, mi);
    }

    sort(A.begin(),A.end());

    long long ans = 0;
    for (int i = 0; i < N; ++i) ans += abs (A[i]);
    auto iter = upper_bound(A.begin(),A.end(),0);
    while (mi + zr < pl){
        int cnt = 0;
        for (int i = 0; iter + i < A.end(); ++i) {
            if (*iter == *(iter + i)) ++cnt;
            else break;
        }
        mi += zr;
        zr = cnt;
        pl -= cnt;
        iter += cnt;

        if (mi + zr >= pl){
            iter -= cnt;
            break;
        }
    }
    long long sum = 0;
    int desc = *iter;
    for (int i = 0; i < N; ++i){
        A[i] -= desc;
        sum += abs (A[i]);        
    }
    cout << min (ans,sum) << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}
