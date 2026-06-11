#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, T, A;
    cin >> N;
    cin >> T >> A;
    typedef pair<double, int> Pos;
    priority_queue<Pos, vector<Pos>, greater<Pos>> que;
    for(int i=0; i<N; i++){
        int h;
        cin >> h;
        double diff_t = abs((T - h*0.006) - A);
        Pos pos = Pos(diff_t, i);
        que.push(pos);
    }

    Pos target = que.top();
    cout << target.second + 1 << endl;
    return 0;
}