#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// editorial解
// 青い点をx座標の小さい順に見て
// ペアになれる赤点の内、もっともy座標が大きいペアを探しペアにする
// なかったらなにもしない

const int MAX_N = 200;
bool visited[MAX_N];
pair<int,int> red[MAX_N], blue[MAX_N];
int N;

int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> red[i].first >> red[i].second;
    for(int i = 0; i < N; ++i) cin >> blue[i].first >> blue[i].second;

    sort(blue, blue + N);
    sort(red, red + N);
    int res = 0;
    for(int i = 0; i < N; ++i) {
        int candidate = -1, y = -1;
        for(int j = 0; red[j].first < blue[i].first && j < N; ++j) {
            if(red[j].second < blue[i].second && y < red[j].second) 
                if(!visited[j]) candidate = j, y = red[j].second;
        }
        if(candidate != -1 ) visited[candidate] = true, ++res;
    }
    cout << res << endl;
    return 0;
}