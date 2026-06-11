#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct edge{
    int to;
    int dist;
    edge(int a, int b){
        to=a;
        dist=b;
    }
};

int n,m,c[100000],NINF=-1e9-7;
vector<edge> v[100000];
set<int> s;

bool f(int a, int b){
    bool g=true;
    if(c[a]==NINF){
        c[a]=b;
        //cout<<"---"<<a<<":c="<<b<<endl;
        for(int i=0;i<v[a].size()&&g;i++){
            g=f(v[a][i].to, c[a]+v[a][i].dist);
        }
    }else if(c[a]!=b){
        //cout<<"---"<<a<<":c="<<c[a]<<"!="<<b<<endl;
        return false;
    }
    return g;
}


int main(void){
    bool h=true;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        s.insert(i);
        c[i]=NINF;
    }
    for(int i=0;i<m;i++){
        int l,r,d;
        cin>>l>>r>>d;
        l--;
        r--;
        v[l].push_back(edge(r,d));
        v[r].push_back(edge(l,-d));
        //s.erase(r);
    }
    for(int i=0;i<n&&h;i++){
        if(c[i]==NINF){
            //cout<<"---"<<i<<":c=0"<<endl;
            h=f(i, 0);
        }
    }

    if(h){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
