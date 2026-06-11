#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)

int main(){
    int h,w;
    cin>>h>>w;

    vector<vector<int>> map(h,vector<int>(w,0));
    queue<pair<int,int>> q;
    rep(i,0,h){
        rep(j,0,w){
            char tmp;
            cin>>tmp;
            if(tmp=='.') map.at(i).at(j)=-1;
            else q.push(make_pair(i,j));
        }
    }

    vector<pair<int,int>> delta={make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(0,1)};

    int depth=0;
    while(!q.empty()){
        pair<int,int> pos=q.front();
        q.pop();

        for(auto d:delta){
            pair<int,int> next_p=make_pair(pos.first+d.first, pos.second+d.second);

            if(next_p.first>=0 && next_p.first<h && next_p.second>=0 && next_p.second<w){
                if(map.at(next_p.first).at(next_p.second)==-1){
                    int new_depth=map.at(pos.first).at(pos.second)+1;
                    map.at(next_p.first).at(next_p.second)=new_depth;
                    q.push(next_p);
                    depth=max(depth,new_depth);
                }
            }
        }
    }

    cout<<depth<<endl;
}