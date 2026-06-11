#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int a,b,c,n;
int l[10];
int ans = inf;

void dfs(int tmp_a,int tmp_b, int tmp_c,int now, int magic)
{
    if(now == n){
        if(tmp_a * tmp_b * tmp_c != 0){
            magic += abs(tmp_a-a);
            magic += abs(tmp_b-b);
            magic += abs(tmp_c-c);
            ans = min(magic,ans);
        }
    }else{
        if(tmp_a == 0){
            dfs(tmp_a+l[now],tmp_b,tmp_c,now+1,magic);
        }else{
            dfs(tmp_a+l[now],tmp_b,tmp_c,now+1,magic+10);
        }
        if(tmp_b == 0){
            dfs(tmp_a,tmp_b+l[now],tmp_c,now+1,magic);
        }else{
            dfs(tmp_a,tmp_b+l[now],tmp_c,now+1,magic+10);
        }
        if(tmp_c == 0){
            dfs(tmp_a,tmp_b,tmp_c+l[now],now+1,magic);
        }else{
            dfs(tmp_a,tmp_b,tmp_c+l[now],now+1,magic+10);
        }
        dfs(tmp_a,tmp_b,tmp_c,now+1,magic);
    }
}

int main()
{
    cin >> n >> a >> b >> c;
    rep(i,n) cin >> l[i];
    dfs(0,0,0,0,0);
    cout << ans << endl;

}