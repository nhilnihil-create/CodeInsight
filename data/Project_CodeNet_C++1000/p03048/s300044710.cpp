#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=3.14159265358979323846;

int main () {

    ll R,G,B,N;
    cin >> R >> G >> B >> N;

    ll a,b,c,ans;
    ans = 0;
    a=b=c=0;
    while(a<=N) {
        b=0;
        while(a+b<=N) {
            if((N-a-b)%B==0) {
                ans++;
            }
            b+=G;
        }
        a+=R;
    }
    cout << ans << endl;

}