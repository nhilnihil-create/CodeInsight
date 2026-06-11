#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int L;
    cin>>L;
    int N = 1, count = L;
    while(count > 0){
        N++;
        count /= 3;
    }
    vector<vector<int>> G;
    vi keta(N, 0), triple(N, 0);
    int i = 0, j = 1;
    REP(i, 0, N){
        keta[i] = L%3;
        triple[i] = j;
        L /= 3; j *= 3;     
    }
    reverse(keta.begin(), keta.end());
    int M = 0;
    REP(i, 0, N-2){
        REP(j, 0, 3){
            vi edge = {i+1, i+2, triple[i]*j};
            G.emplace_back(edge);
            M++;
        }
    }
    int max = 0;
    REP(i, 0, N){
        if(keta[i]){
            REP(j, 0, keta[i]){            
                vi edge = {N-i, N, max};            
                G.emplace_back(edge);
                max += triple[N-i-1];
                M++;
            }
        }
    }
/*
    cout << N << endl;
    REP(i, 0, N) cout << keta[i] << " ";
    cout << endl;
    */
    cout << N << " " << M << endl;
    for(auto x: G){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
}