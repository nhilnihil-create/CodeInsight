#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

typedef long long ll;
ll mod=1000000007;
typedef pair<int, int> P;

ll N,K;

int main()
{
    cin >> N >> K;
    ll ans=0;
    for(int b=K+1; b<=N; b++){
        if(K==0) ans--;
        ans+=N/b*(b-K);
        ans+=max(N%b-K+1, (ll)0);
    }

    cout << ans << endl;
    

    return 0;
}
