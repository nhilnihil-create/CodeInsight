#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> p(100005);
vector<int> r(100005);
void pre(){
    for(int i=1;i<100005;i++) p[i]=i;
}
int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}
void un(int g,int h){
    int a=find(g),b=find(h);
    if(a==b) return;
    if(r[a]>r[b]) p[b]=p[a];
    else {p[a]=p[b];if(r[a]==r[b]) r[a]++;}
}
int main(){
    pre();
    int n,m,a,b,c,t=0;cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        un(a,b);
    }
    for(int i=1;i<=n;i++) if(p[i]==i) t++;
    cout<<t;   
}