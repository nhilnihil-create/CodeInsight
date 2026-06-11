#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long N;
long long ans;
vector<int> use;
void dfs(long long a, long long b, vector<int> use){
    if(b == 3) use[0] = 1;
    else if(b == 5) use[1] = 1;
    else if(b == 7) use[2] = 1;
    if(a * 10 + b > N) return;
    else{
        int flag = 0;
        for(int i = 0; i < 3; i++){
            if(use[i] == 0) flag = 1;
        }
        if(flag == 0) {
            ans++;
        }

    }
    dfs(a * 10 + b, 3, use);
    dfs(a * 10 + b, 5, use);
    dfs(a * 10 + b, 7, use);
}
int main(){
    cin >> N;
    use.resize(3, 0);
    ans = 0;
    dfs(0, 3, use);
    dfs(0, 5, use);
    dfs(0, 7, use);
    cout << ans << endl;
}