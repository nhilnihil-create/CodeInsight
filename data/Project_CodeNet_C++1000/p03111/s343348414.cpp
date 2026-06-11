#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int ans = 1000000;
int l[100] = {0};
void dfs(int cost, int i, int la, int lb, int lc){
    if(i == n) {
        if(la*lb*lc > 0){
            cost += abs(a-la) + abs(b-lb) + abs(c-lc);
            ans = min (ans, cost);
        }
    }
    else{
        dfs(cost,i+1,la,lb,lc);
        dfs(cost + 10*(la!=0),i+1,la + l[i],lb,lc);
        dfs(cost + 10*(lb!=0),i+1,la,lb + l[i],lc);
        dfs(cost + 10*(lc!=0),i+1,la,lb,lc + l[i]);
    }
}

int main(){
    cin >> n >> a >>b >>c;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    dfs(0,0,0,0,0);
    cout << ans << endl;
    

}