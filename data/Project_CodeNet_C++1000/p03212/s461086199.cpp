#include <bits/stdc++.h>
using namespace std;
int N, K;


void dfs(long long now, long long &ans, vector<int> use){
    if (now > N)
    {
        return;
    }
    if (use[0] != 0 && use[1] != 0 && use[2] != 0)
    {
        ans++;
    }
    
    use[0]++;
    dfs(now * 10 + 3, ans, use);
    use[0]--;
    use[1]++;
    dfs(now * 10 + 5, ans, use);
    use[1]--;
    use[2]++;
    dfs(now * 10 + 7, ans, use);
    use[2]--;
    
}

int main(){
    cin >> N;
    // K = to_string(N).size();
    long long ans = 0;
    vector<int> use(3);
    dfs(0, ans, use);
    cout << ans << endl;
    return 0;
}