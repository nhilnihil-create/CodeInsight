#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

vector<int> G[200200];
int per,mx;
void dfs(int s,int f,int now=0){
    if(mx<now){
        mx=now;
        per=s;
    }
    for(int t:G[s]){
        if(t==f)continue;
        dfs(t,s,now+1);
    }
}

int main(){
    int n; cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    mx=-1;
    dfs(0,-1);
    dfs(per,-1);
    if(mx%3==1){
        cout << "Second" << endl;
    }
    else{
        cout << "First" << endl;
    }
}