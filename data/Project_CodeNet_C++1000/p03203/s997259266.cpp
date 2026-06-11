#include <iostream>
#include <map>  // pairはutilityヘッダにあり、mapヘッダから読み込まれる
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;
/*
bool operator< (const p p1, const p p2){
    return p1.first < p2.first;
};
*/


int main(){
    int N;
    int H, W;
    priority_queue<p> que;
    map<int, int> m;
    cin >> H >> W >> N;
    for(int i = 0; i < N; i++){
        int X, Y;
        cin >> X >> Y;
        que.push(make_pair(-X, Y));
    }
    int cur_diff = 0;
    
    int len = que.size();
    for(int i = 0; i < len; i++){
        //cout << -que.top().first << ' ' << que.top().second << endl;
        if(que.top().first + que.top().second == cur_diff) cur_diff--;
        else if(que.top().first + que.top().second < cur_diff){
            //cout << cur_diff << endl;
            cout << -que.top().first - 1 << endl;
            return 0;
        }
        que.pop();
    }
    cout << H << endl;
}