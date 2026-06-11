#include<bits/stdc++.h>
using namespace std;
vector<int> rel[1000000];
bool checked[1000000];

void dfs(int i){
    checked[i] = true;
    for (int j : rel[i])
    {
        if(!checked[j]){
            dfs(j);
        }
    }    
}

int main(){
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin>> a >> b >> c;
        rel[a-1].push_back(b-1);
        rel[b-1].push_back(a-1);
    }
    memset(checked,false, sizeof(checked));
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(!checked[i]){
            dfs(i);
            sum ++ ;
        }
    }
    cout << sum << endl; 
}
