#include <bits/stdc++.h>
using namespace std;
long long int ans;
long long int n;
void dfs(long long int tmp, bool flag3, bool flag5, bool flag7){
    if(tmp > n){//nより大きくなったらそこの探索終わり
        return;
    }

    if(flag3 && flag5 && flag7){
        //cout << tmp << endl;
        ans++;
    }

    dfs(tmp*10 + 3, true, flag5, flag7);//3を末尾に追加
    dfs(tmp*10 + 5, flag3, true, flag7);//5を末尾に追加
    dfs(tmp*10 + 7, flag3, flag5, true);//7を末尾に追加
}

int main(){
    ans = 0;
    cin >> n;
    dfs(0, 0, 0, 0);
    cout << ans << endl;
}