#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    int N, M, ans;   cin >> N >> M;
    ans = pow(2,M)*(M*1900+(N-M)*100);
    cout << ans << endl;
    return 0;
}