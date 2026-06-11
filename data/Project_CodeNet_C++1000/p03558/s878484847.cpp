#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int K;
    cin >> K;
    int d[K+1]; //modK = 0,1,2,....,K-1
    fill(d, d + K, 1e9); 
    d[1] = 1;
    deque<int> que;
    que.push_back(1);
    while(!que.empty()) {
        int p = que.front(); que.pop_front();
        if(d[(p+1)%K] > d[p] + 1) {
            //1の位が9の時の辺は、より小さい数から10倍して行った方が距離が短く、
            //行き先の頂点がすでに訪れられていることがわかるので、
            //考慮しなくても良いことがわかる。
            //例, 1->10->11->,,,->19->20 よりも、1->2->20の方が距離が短い
            d[(p+1)%K] = d[p] + 1; que.push_back((p+1)%K);
        }
        if(d[(p*10)%K] > d[p]) {
            d[(p*10)%K] = d[p]; que.push_front((p*10)%K);
        }
        /*
        for(int i = 0; i < K; ++i) {
            cout << d[i] << " ";
        }
        cout << endl;
        */
    }
    cout << d[0] << endl;
    return 0;
}