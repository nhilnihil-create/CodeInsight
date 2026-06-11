#include <iostream>
#include <set>
using namespace std;
int cnt = 0;
int cnt2 = 0;
bool check(long long x, int n){
    bool ans;
    set<int> st;
    while(x){
        st.insert(x%10);
        x /= 10;
    }
    if(st.size() == 3) ans = true;
    else ans = false;
    return ans;
}
void dfs(long long x,int n){
    if(n < x) return;
    if(check(x,n)) cnt++;
    dfs(10*x+3,n);
    dfs(10*x+5,n);
    dfs(10*x+7,n);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    dfs(0,n);
    cout << cnt << endl;
    return 0;
}
//Saw the solution video