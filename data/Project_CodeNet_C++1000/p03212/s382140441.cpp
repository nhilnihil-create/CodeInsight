#include <iostream>
#include <vector>

using namespace std;
#define ll long long

vector<int> A;

int N;

void dfs(ll &ans, ll current_num, bool seven, bool five, bool three){
    if(current_num > N){
        return;
    }

    if(seven && five && three) ans++;

    dfs(ans, current_num * 10 + 7, true, five, three);
    dfs(ans, current_num * 10 + 5, seven, true, three);
    dfs(ans, current_num * 10 + 3, seven, five, true);
}

int main(void){
    cin >> N;

    ll ans = 0;
    dfs(ans, 0, false, false, false);

    cout << ans << endl;
    return 0;
}