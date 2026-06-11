#include<bits/stdc++.h>
using namespace std;
#define int long long
//#undef int
#define mk make_pair
#define pb push_back
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;

int H, W, N;
pii p[200005];
map<pii, bool> mp;
int R[200005];
int L[200005];

signed main()
{
    cin >> H >> W >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        p[i] = mk(a, b);
        mp[p[i]] = true;
    }
    int r = 0;
    for(int i = 1; i < H; i++){
        if(!mp[mk(i, r + 1)]){
            r++;
        }
        R[i] = r;
    }
    fill(L, L + H, INF);
    sort(p, p + N);
    for(int i = N - 1; i >= 0; i--){
        L[p[i].first] = p[i].second;
    }
    int ans = H;
    for(int i = 1; i < H; i++){
        if(L[i] <= R[i]){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    /*for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(mp[mk(i, j)]){
                printf("#");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }*/

    return 0;
}

/*

7
3
13
15
1
31
33
1

*/
