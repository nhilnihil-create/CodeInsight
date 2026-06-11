#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;

// 解説を読んだ 賢い

int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<int> v[n];
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> color(n, -1);
    stack<pair<int,int>> s;
    s.push({0,1});
    bool bigraph = true;
    while(!s.empty()){
        auto p = s.top(); s.pop();
        int i = p.first, j = p.second;
        if(color[i] == j)   continue;
        if(color[i] != -1){
            bigraph = false;
        }
        color[i] = j;
        for(int next : v[i]){
            if(color[next] == -1){
                s.push({next, 1-j});
            }else if(color[next] != 1-j){
                bigraph = false;
                break;
            }
        }
        if(!bigraph)    break;
    }
    if(bigraph){
        int cnt = 0;
        for(int i = 0; i < n; i++)  cnt += color[i] == 0;
        cout << (ll)(cnt)*(n-cnt)-m << endl;
    }else{
        cout << (ll)n*(n-1)/2-m << endl;
    }
    return 0;
}