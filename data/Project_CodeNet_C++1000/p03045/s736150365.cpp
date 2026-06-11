#include<bits/stdc++.h>
using namespace std;
int sum = 0;

void dfs(int i, int pre, vector<vector<int>> &rel,vector<bool> &checked){
    bool all_checked = true;
    for (int j : rel[i])
    {
        if(!checked[j]) all_checked = false;
    }
    if(all_checked) return;
    for (int j : rel[i])
    {
        if(j == pre) continue;
        if(!checked[j]){
            checked[j] = true;
            dfs(j,i,rel,checked);
        }
    }    
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> rel(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin>> a >> b >> c;
        rel[a-1].push_back(b-1);
        rel[b-1].push_back(a-1);
    }
    int sum = 0;
    vector<bool> checked(n,false);
    for (int i = 0; i < n; i++)
    {
        if(!checked[i]){
            checked[i] = true;
            dfs(i,-1,rel,checked);
            sum ++ ;
        }
    }
    cout << sum << endl; 
}