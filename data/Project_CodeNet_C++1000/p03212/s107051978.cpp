#include <bits/stdc++.h>
using namespace std;
int n,ans;
void dfs(int sum,char ss){
    if(sum>n)return;
    if(ss==7)ans++;
    if(sum<99999999){
        dfs(sum*10+3,ss|1);
        dfs(sum*10+5,ss|2);
        dfs(sum*10+7,ss|4);
    }
}
int main(){
    cin>>n;
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}