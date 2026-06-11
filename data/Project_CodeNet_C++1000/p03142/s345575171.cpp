#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int ind[100005]={0};
int ini[100005];
vector<int> otd[100005];
vector<pair<int,int> > edge;
queue<int>q;
int dis[100005];
bool vis[100005];
int n, m, i, a, b;

void bfs(int s){
    for(i=1; i<=n; i++)vis[i]=false;
    dis[s]=0;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        a=q.front();
        q.pop();
        for(i=0; i<otd[a].size(); i++){
            b=otd[a][i];
            if(ind[b]==1){
            if(!vis[b]){
                vis[b]=true;
                ini[b]=a;
                q.push(b);
                dis[b]=dis[a]+1;
            }
            }
            else{ ind[b]--;}
        }
    }
}

int main()
{
    cin>> n>> m;
    for(i=0; i<n-1+m; i++){
        cin>> a>> b;
        ind[b]++;
        otd[a].push_back(b);
        edge.push_back(make_pair(a,b));
    }
    int trav=0, x;
    //cout<< endl;
    //for(i=1; i<=n; i++)cout<< i<< " "<< ind[i].size()<< " "<< otd[i].size()<< endl;
    for(i=1; i<=n; i++){
        vis[i]=false;
        if(ind[i]==0)x=i;
    }
    bfs(x);
    //cout<< endl;
    //for(int o=1; o<=n; o++)cout<< dis[o]<< " ";
    //cout<< endl;

//    for(i=0; i<m; i++){
//        for(int j=1; j<=n; j++){
//            if(ind[j].size()>1){
//                for(int k=0; k<ind[j].size(); k++){
//                    b=ind[j][k];
//                    if(dis[b]<dis[j]){
//                        ind[j].erase(find(ind[j].begin(),ind[j].end(),b));
//                        otd[b].erase(find(otd[b].begin(),otd[b].end(),j));
//                        edge.erase(find(edge.begin(),edge.end(),make_pair(b,j)));
//                        //cout<< b<< " "<< j<< endl;
//                        //for(int o=1; o<=n; o++)cout<< dis[o]<< " ";
//                        //cout<< endl;
//                        bfs(x);
//                    }
//                }
//            }
//        }
//    }
//    //cout<< endl;
//    //for(i=1; i<=n; i++)cout<< i<< " "<< ind[i].size()<< " "<< otd[i].size()<< endl;
//    //cout<< endl;
    for(i=1; i<=n; i++)cout<< ini[i]<< endl;
}
