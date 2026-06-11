#include<bits/stdc++.h>
using namespace std;
#define int long long
//#undef int
#define mk make_pair
#define pb push_back
#define pf push_front
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

int N;
int d[100100];
deque<int> dque;

signed main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        d[i] = INF;
    }
    d[1] = 1;
    dque.pf(1);
    while(dque.size()){
        int cur = dque.front();
        dque.pop_front();
        int nxt = cur * 10 % N;
        if(d[nxt] > d[cur]){
            d[nxt] = d[cur];
            dque.pf(nxt);
        }
        nxt = (cur + 1) % N;
        if(d[nxt] > d[cur] + 1){
            d[nxt] = d[cur] + 1;
            dque.pb(nxt);
        }
    }
    cout << d[0] << endl;



    return 0;
}
/*


*/


