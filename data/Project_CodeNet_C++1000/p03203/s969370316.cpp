#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

vector<int> G[MAX_N];

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    rep(i,n){
        int x, y;
        cin >> x >> y;
        G[y].push_back(x);
    }
    rep(i,MAX_N){
        G[i].push_back(h+1);
        sort(G[i].begin(), G[i].end());
    }
    rep(j,MAX_N){
        G[w+1].push_back(j);
    }

    int ans = h;

    int x = 1, y = 1;

    while(x < ans){
        // cout << x << ' ' << y << endl;
        auto ite = lower_bound(G[y].begin(), G[y].end(), x+1);
        ans = min(ans, *ite-1);
        if(ans == x)break;
        int flag = 0;
        while(x < ans){
            x++;
            ite = lower_bound(G[y+1].begin(), G[y+1].end(), x);
            if(*ite == x){
                ;
            }else{
                y++;
                flag = 1;
                break;
            }
        }
        if(flag == 0)break;
    }

    cout << ans << endl;
    return 0;
}


