#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iomanip>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

using namespace std;

int main()
{
    int N, K;   cin >> N >> K;
    int tmp, cnt;
    long double ans=0.0, t;
    for(int i=1; i<=N; i++){
        tmp = i;
        t = 1.0/N;
        while(tmp < K){
            tmp *= 2;
            t *= 0.5;
        }
        ans += t;
    }
    cout << std::fixed << std::setprecision(15) << ans;
}