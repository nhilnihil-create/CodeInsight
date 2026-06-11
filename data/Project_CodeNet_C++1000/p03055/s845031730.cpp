

/// if diameter of tree%3== 0 or 2, first. else second.

#include <bits/stdc++.h>
using namespace std;

vector<int> adjl[200005];
vector<int> children[200005];
int longest_[200005];
int secondLongest_[200005];
int longestchild[200005];
int parent[200005];
int n;

void dfs(int node){
for (int x : adjl[node]){
    if (x==parent[node]) continue;
    parent[x] = node;
    dfs(x);
}
}

int longest(int node){
if (longest_[node] !=-1) return longest_[node];
if (children[node].size()==0) return 0;
else{
    int ans = 0;
    for (int x : children[node]){
        if (longest(x)+1>ans){
            ans = longest(x) +1;
            longestchild[node] = x;
        }
    }

return longest_[node] = ans;
}}

int secondLongest(int node){
longest(node);
if (secondLongest_[node]!=-1) return secondLongest_[node];
if (children[node].size()<2) return 0;
int ans = 0;
for (int x : children[node]){
    if (x == longestchild[node]){
        continue;
    }
    ans = max(ans,longest(x)+1);
}
return secondLongest_[node] = ans;
}

int diameter(){
int ans = 0;
for (int x = 0; x<n; x++){
    ans = max(ans,longest(x) + secondLongest(x));
}
return ans;
}

int main(){
memset(longest_,-1,sizeof(longest_));
memset(secondLongest_,-1,sizeof(secondLongest_));

scanf("%d",&n);
int a,b;
for (int x = 0; x<n-1; x++){
    scanf("%d%d",&a,&b);
    a--;b--;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
}
parent[0] = -1;
dfs(0);

for (int x = 0; x<n; x++){
    for (int y : adjl[x]){
        if (y!=parent[x]){
            children[x].push_back(y);
        }
    }
}
/*
printf("%d\n",diameter());
for (int x = 0; x<n; x++){
    printf("longest (%d) = %d, secondlongest = %d\n",x,longest(x),secondLongest(x));
}*/

if (diameter()%3==1){
    printf("Second");
}
else printf("First");




}
