#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int n;

void bfs(vector<vector<pair<int,int>>> &vec,vector<int> &ans,int color,int start){
    int e,v,c=0;
    vector<int> vc(n,-1);//それぞれの頂点をつっこむ時に使った色
    queue<pair<int,int>> q;
    for(auto p:vec[start]){
        q.push(p);
        ans[p.first]=c%color;
        vc[p.second]=c%color;
        c++;
    }
    while(!q.empty()){
        auto p=q.front();q.pop();
        e=p.first;v=p.second;
        c=vc[v]+1;
        for(auto np:vec[v]){
            if(ans[np.first]!=-1)continue;
            q.push(np);
            ans[np.first]=c%color;
            vc[np.second]=c%color;
            c++;
        }
    }
}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
  int x,y;cin>>x>>y;
  if(x%y==0)cout<<-1<<endl;
  else cout<<x<<endl;
}
