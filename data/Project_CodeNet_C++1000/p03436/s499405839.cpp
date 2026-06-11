#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int H, W;cin>>H>>W;
    //vector<vector<int>> s(H, vector<int>(W,0));
    vector<string> s(H);
    int tot_white=0;
    rep(i,H){
        cin>>s.at(i);
        rep(j,W){
            if(s.at(i).at(j)=='.')tot_white++;
        }
        /*
        rep(j,W){
            cin>>s.at(i).at(j);
            if(s.at(i).at(j)=='.')tot_white++;
        }
        */
    }

    // ダイクストラ法でゴールまでの最短経路を求める

    priority_queue<T, vector<T>,greater<T>> pq;
    pq.push(make_tuple(0, 0, 0));

    vector<vector<int>> min_distance(H, vector<int>(W,-1));

    while(pq.size()>0){
        int cost, h, w;
        tie(cost, h, w) = pq.top();pq.pop();
        if(h==H-1 && w==W-1){
            cout<<tot_white-cost-1<<endl;
            return 0;
        }
        if(min_distance.at(h).at(w)>=0)continue;
        min_distance.at(h).at(w) = cost;

        for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if(abs(i)+abs(j)!=1)continue;
            if(h+i<0||h+i>H-1)continue;
            if(w+j<0||w+j>W-1)continue;
            if(min_distance.at(h+i).at(w+j)>=0)continue;
            if(s.at(h+i).at(w+j)=='#')continue;
            pq.push(make_tuple(cost+1, h+i, w+j));
        }
        }


    }

    cout<<-1<<endl;

    return 0;
}