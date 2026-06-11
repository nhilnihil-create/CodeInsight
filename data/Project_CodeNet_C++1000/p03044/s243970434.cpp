#include <bits/stdc++.h>
using namespace std;
int n,p1,p2,p3,col[100001];
vector<pair<int,int> > arr[100001];
void dfs(int cur,int pre,int c) {
    col[cur]=c;
    for (int i=0; i<arr[cur].size(); i++) {
        if (arr[cur][i].first==pre) continue;
        if (arr[cur][i].second%2==0) dfs(arr[cur][i].first,cur,c);
        else dfs(arr[cur][i].first,cur,!c);
    }
}
int main() {
    cin>>n;
    for (int i=0; i<n-1; i++) {
        cin>>p1>>p2>>p3; p1--; p2--;
        arr[p1].push_back({p2,p3});
      	arr[p2].push_back({p1,p3});
    }
    dfs(0,-1,0);
    for (int i=0; i<n; i++) cout<<col[i]<<'\n';
}