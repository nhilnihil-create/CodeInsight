#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define loop(i, n) for(int i = 0;i < n;i++)
#define INF 1000000000

int main(void){

    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    loop(i, d) cin >> p[i] >> c[i];

    int ans = INF;

    loop(bit, 1 << d){
        int point = 0;
        int count = 0;
        loop(i, d){
            if(bit & (1 << i)){
                point += (i+1) * 100 * p[i] + c[i];
                count += p[i];
            }
        }
        if(point >= g){
            ans = min(ans, count);
            continue;
        }
        loop(i, d){
            if(bit & (1 << i)) continue;
            if((g - point)/((i+1)*100) <= p[i]){
                count += (g - point)/((i+1)*100);
                ans = min(ans, count);
            }
        }
    }

    cout << ans << endl;

    return 0;
}