#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <sstream>
using namespace std;
using i64 = int64_t;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep2(i, x, n) for(int i=x;i<n;++i)

int main()
{   
    int n,k;
    cin >> n >> k;
    i64 cnt = 0;
    rep2(i,k+1,n+1)
        cnt += (n/i)*(i-k) + max(0,(n%i)-k+1) - int(k==0);        
    cout << cnt << endl;
    return 0;
}