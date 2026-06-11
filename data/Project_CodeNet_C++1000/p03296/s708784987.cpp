#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
 
int main()
{
    int N; cin >> N;
    vector<int> a(N + 9); rep(i, N) cin >> a[i];

    int ans = 0;
    int prev = a[0];
    for (int i = 1; i < N; ++i){
        if (prev == a[i]){
            ++ans;
            a[i] = 100 + ans;
            prev = a[0];
            i = 0;
        } else {
            prev = a[i];
        }
    }

    cout << ans << endl;
    return 0;
}
