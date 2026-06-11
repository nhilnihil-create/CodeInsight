#include <bits/stdc++.h>
using namespace std;
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

int main(){
    int N; cin>>N;
 //   vec_int u(N),v(N),w(N);

    vector<vector<P>> G(N+1);
    rep(i,N){
        int u,v,w;
        cin>>u>>v>>w;
        G.at(u).push_back(make_pair(v,w));
        G.at(v).push_back(make_pair(u,w));
    }


    //木だから全部つながっていると思ってよい
    //0から幅優先探索で次のノードとの距離がぐうすうだったら同じ色、奇数だったら違う色を塗る

    vec_int visited(N+1,0);
    vec_int color(N+1);
    //幅優先探索だからqueを使う
    queue<T> q;
    //T: next_node, distance, current_color
    q.push(make_tuple(1,0,0));
    while(!(q.empty())){
        T pos = q.front();q.pop();
        int node, distance,prev_color;
        tie(node,distance,prev_color) = pos;
        if(visited.at(node)==1)continue;
        visited.at(node)=1;
        //色を付ける
        color.at(node) = distance%2==0 ? prev_color : (prev_color==1? 0 : 1);

        for(int i=0;i<G.at(node).size();i++){
            P temp = G.at(node).at(i);
            int next_pos, next_distance;
            tie(next_pos,next_distance) = temp;
            if(visited.at(next_pos)==1)continue;
            q.push(make_tuple(next_pos,next_distance,color.at(node)));
        }
    }

    for(int i=1;i<N+1;i++){
        cout<<color.at(i)<<endl;
    }









    return 0;
}