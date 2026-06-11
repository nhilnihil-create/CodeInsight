#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, M, Q;
    int l, r;

    cin >> N >> M >> Q;
    vector<int> L(M);
    vector<int> R(M);
    vector<int> p(Q);
    vector<int> q(Q);

    for (int i=0; i<M; i++){
        cin >> l >> r;
        L[i] = l-1;
        R[i] = r-1;
    }
    for (int i=0; i<Q; i++){
        cin >> l >> r;
        p[i] = l-1;
        q[i] = r-1;
    }

    vector<vector<int> > coordinate(N, vector<int>(N, 0)), cumsum(N, vector<int>(N+1, 0));
    for (int coord_idx=0; coord_idx<M; coord_idx++){
        coordinate[L[coord_idx]][R[coord_idx]] += 1;
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cumsum[i][j+1] = cumsum[i][j] + coordinate[i][j];
        }
    }

    int result=0, query_l, query_r;
    for (int query_idx=0; query_idx<Q; query_idx++){
        result = 0;
        query_l = p[query_idx];
        query_r = q[query_idx];
        for (int i=query_l; i<=query_r; i++){
            result += cumsum[i][query_r+1] - cumsum[i][query_l];
        }
        cout << result << endl;
    }
    
}
