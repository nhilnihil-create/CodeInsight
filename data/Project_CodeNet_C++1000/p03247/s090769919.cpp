#include<bits/stdc++.h>
using namespace std;
#define int long long
//#undef int
#define mk make_pair
#define pb push_back
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

int N, X[1010], Y[1010];
vector<int> v;

int abso(int a)
{
    if(a > 0)return a;
    return -a;
}

signed main()
{
    cin >> N;
    int a = 0, b = 0, D = 0ll;
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
        int x = X[i];
        int y = Y[i];
        int d = abso(x) + abso(y);
        if(d % 2){
            a++;
        }
        else{
            b++;
        }
        D = max(D, d);
    }
    if(a > 0 && b > 0){
        printf("-1\n");
        return 0;
    }
    int n = 1;
    v.pb(1ll);
    if(D % 2 == 0ll){
        v.pb(1ll);
    }
    while(n < D){
        n *= 2ll;
        v.pb(n);
    }
    int S = v.size();
    printf("%lld\n", S);
    for(int i = 0; i < S; i++){
        printf("%lld", v[i]);
        if(i < S - 1){
            printf(" ");
        }
    }
    printf("\n");
    reverse(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        int x = X[i];
        int y = Y[i];
        string s;
        for(int j = 0; j < S; j++){
            int dx = abso(x);
            int dy = abso(y);
            char dir;
            //printf("%lld x:%lld y:%lld\n", i, x, y);
            if(dx >= dy){
                if(x > 0){
                    x -= v[j];
                    dir = 'R';
                }
                else {
                    x += v[j];
                    dir = 'L';
                }
            }
            else{
                if(y > 0){
                    y -= v[j];
                    dir = 'U';
                }
                else{
                    y += v[j];
                    dir = 'D';
                }
            }
            s += dir;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }

    return 0;
}

/*


*/
