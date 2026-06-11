#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, D, Q;
    cin >> H >> W >> D;
    vector<array<int,2>> A(H*W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int k;
            cin >> k;
            A[k-1] = array<int, 2>{i, j};
        }
    }
    vector<vector<int>> cost(D);
    for(int i=0;i<D;i++){
        cost[i].push_back(0);
        for(int j=i; j+D<H*W; j+=D){
            auto x1 = A[j];
            auto x2 = A[j+D];
            auto c = abs(x1[0] - x2[0]) + abs(x1[1] - x2[1]);
            cost[i].push_back(c + cost[i].back());
        }
    }

    cin >> Q;
    int R, L;
    vector<int> res(Q);
    for(int i=0;i<Q;i++){
        cin >> L >> R;
        R--; L--;
        res[i] = cost[R%D][R/D] - cost[L%D][L/D];
    }
    for(auto v : res) cout << v << endl;

    return 0;
}