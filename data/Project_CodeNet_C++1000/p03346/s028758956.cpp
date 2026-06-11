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
    int N;
    cin>>N;
    vi P(N), pos(N);
    REP(i, 0, N){
        int p ;
        cin >> p;
        P[i] = p;
        p--;
        pos[p] = i;
    }
    int max = 0, count = 0, max_len = 0;
    REP(i, 0, N + 1){
        if(pos[i] > max && i != N){
            max = pos[i];
            count++;
        }else{
            max = pos[i];
            max_len = std::max(count, max_len);
            count = 1;
        }
    }
    cout << N - max_len << endl;
}