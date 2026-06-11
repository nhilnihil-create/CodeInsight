#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> p(N);
    for(int i=0; i<N; i++)
        cin >> p[i];
    vector<int> pinv(N+1);
    for(int i=0; i<N; i++)
        pinv[p[i]] = 2*i+1;

    vector<long long> dp0(2*(N+1), 1LL<<60);
    dp0[0] = 0;
    for(int i=1; i<=N; i++){
        vector<long long> dp1(2*(N+1), 1LL<<60);
        long long mn = 1LL<<60;

        for(int j=0; j<pinv[i]; j+=2){
            mn = min(mn, dp0[j]);
            dp1[j] = mn + B;
            mn = min(mn, dp0[j+1]);
        }

        dp1[pinv[i]] = mn;

        for(int j=pinv[i]+1; j<=2*N; j+=2){
            mn = min(mn, dp0[j]);
            dp1[j] = mn + A;
            mn = min(mn, dp0[j+1]);
        }
        dp0 = dp1;
    }
    long long ans = 1LL<<60;
    for(int i=0; i<2*(N+1); i++)
        ans = min(ans, dp0[i]);

    cout << ans << endl;
    return 0;
}