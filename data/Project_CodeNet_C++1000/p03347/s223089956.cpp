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
    vi X(N, 0), A(N);
    REP(i, 0, N) cin >> A[i];
    long count = 0;
    REP(i, 0, N){
        if(A[i] > i || (i>=1 && A[i] - A[i-1] >= 2)){
            cout << -1 << endl;
            return 0;
        }else{
            if(i>=1 && A[i] - A[i-1] == 1) count++;
            else count += A[i];
        }
    }
    cout << count << endl;
}