#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
 
using namespace std;

int N,A,B,C; 
int l[8];
int ans = 1e9;
void dfs(int a, int b, int c, int cur, int mp){
    if(cur == N){
        if(min(a,min(b,c)) > 0) ans = min(ans,abs(a-A) + abs(b-B) + abs(c-C) + mp -30);
        return; // A,B,Cすべてに1つ以上竹を使っているとき値の更新
    }
    dfs(a,b,c,cur+1,mp); // cur番目の竹を使わない
    dfs(a+l[cur],b,c,cur+1,mp+10); // cur番目の竹をAの材料に使う
    dfs(a,b+l[cur],c,cur+1,mp+10); // cur番目の竹をBの材料に使う
    dfs(a,b,c+l[cur],cur+1,mp+10); // cur番目の竹をCの材料に使う
    return;
}

int main(){
    cin >> N >> A >> B >> C;

    for (int i = 0; i < N; i++)
    {
        cin >> l[i];
    }
    dfs(0,0,0,0,0);

    cout << ans << endl;
}