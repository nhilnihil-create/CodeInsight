#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N;
void dfs(long long t, int &ans, int cnt){
    if(t <= N && cnt == 7) ans++;
    else if(t > N) return;
    t *= 10;
    dfs(t + 3, ans, cnt | (1 << 0));
    dfs(t + 5, ans, cnt | (1 << 1));
    dfs(t + 7, ans, cnt | (1 << 2));
}
int main(){
    cin >> N;
    int ans = 0;
    dfs(3, ans, (1 << 0));
    dfs(5, ans, (1 << 1));
    dfs(7, ans, (1 << 2));
    cout << ans << endl;
}