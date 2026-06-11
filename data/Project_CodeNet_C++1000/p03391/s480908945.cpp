#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        long long sum = 0, shit = 1e18;
        for(int i = 0; i < n; i++){
                long long x, y;
                cin >> x >> y;
                if(x > y){
                        shit = min(shit, y);
                }
                sum += y;
        }
        cout << sum - min(sum, shit) << "\n";

}

