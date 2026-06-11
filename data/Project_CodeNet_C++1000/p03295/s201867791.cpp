#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    pair<int, int> ba[M];
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ba[i] = make_pair(b, a);
    }
    sort(ba, ba + M);

    int x = ba[0].first;
    int cnt = 1;
    for (int i = 1; i < M; i++)
    {
        if(ba[i].second >= x){
            x = ba[i].first;
            cnt++;
        }
    }

    cout << cnt << endl;
}