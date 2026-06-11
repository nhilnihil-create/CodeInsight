#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

long long N;

int dfs(long long v, bool f_3, bool f_5, bool f_7) {
    if (v > N) return 0;
    return dfs(v * 10 + 3, true, f_5, f_7)
         + dfs(v * 10 + 5, f_3, true, f_7)
         + dfs(v * 10 + 7, f_3, f_5, true)
         + (f_3 && f_5 && f_7);
}

int main() {
    cin >> N;
    long long v = 0;
    cout << dfs(v, false, false, false) << endl;
    
}
