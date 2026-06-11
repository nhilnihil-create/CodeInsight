#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int dfs(int N){
    if(N<=5)return mp[N]=N;
    else{
        if(mp[N]>0)return mp[N];
        else{
            int tmp=1e9;
            for(int i=1;i<=N;i*=6)tmp=min(tmp,dfs(N-i)+1);
            for(int i=1;i<=N;i*=9)tmp=min(tmp,dfs(N-i)+1);
            return mp[N]=tmp;
        }
    }
}
int main(){
    int n;
    cin >> n;
    cout << dfs(n) << endl;
}