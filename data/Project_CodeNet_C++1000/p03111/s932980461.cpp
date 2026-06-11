#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

const int MAX_N = 8;
int N, A, B, C;
int l[MAX_N];

int dfs(int a, int b, int c, int now, int total){
    if(now==N){
        if(a==0 || b==0 || c==0) return 1000000000;
        return total + abs(A-a) + abs(B-b) + abs(C-c) - 30;
    }

    int t1 = dfs(a+l[now], b, c, now+1, total+10);
    int t2 = dfs(a, b+l[now], c, now+1, total+10);
    int t3 = dfs(a, b, c+l[now], now+1, total+10);
    int t4 = dfs(a, b, c, now+1, total);
    
    int ret = min(t1,t2);
    ret = min(ret, t3);
    ret = min(ret, t4);

    return ret;
}

int main(){
    cin >> N >> A >> B >> C;

    for(int i=0; i<N; i++){
        cin >> l[i];
    }

    int ans = dfs(0,0,0,0,0);

    cout << ans << endl;

    return 0;
}
