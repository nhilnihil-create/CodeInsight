#include<bits/stdc++.h>
using namespace std;
struct xy{
int x;int y;}node,top;
const int dx[2] = {-1,1};
int main(){
int n,m;
cin >> n >> m;
vector<string>s(n);
queue<xy>q;
int cur = 0;
for(int i = 0;i<n;i++) cin >> s[i];
for(int i = 0;i<n;i++)
for(int j = 0;j<m;j++){
    if(s[i][j]=='#'){node.x = i;node.y = j;q.push(node);cur++;}
}
int t = 0,tt = 0,curr = 0;
bool ok = 0;
while(!q.empty()){
    top = q.front();
    q.pop();
    for(int i = 0;i<=1;i++)
    {
      if(top.x+dx[i]>=0&&top.x+dx[i]<n&&s[top.x+dx[i]][top.y]=='.'){
        s[top.x+dx[i]][top.y] = '#';
        node.x = top.x+dx[i];node.y = top.y;
        q.push(node);curr++;
        ok = 1;
      }
      if(top.y+dx[i]>=0&&top.y+dx[i]<m&&s[top.x][top.y+dx[i]]=='.'){
        s[top.x][top.y+dx[i]] = '#';
        node.x = top.x;node.y = top.y+dx[i];
        q.push(node);curr++;
        ok = 1;
      }
    }
    //cout << t << ' '<< cur << ' '<<curr <<' '<<ok <<endl;
    t++;
        if(t==cur&&ok){tt++;cur += curr;curr = 0;ok = 0;}
}
//cout << t <<endl;
   cout << tt;
   return 0;
}