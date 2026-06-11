#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
int main() {
    int N,M,C;
    cin >> N >> M >> C;
    //
    vector<int> B(M);

    for(int i=0;i<M;i++){
        cin >> B[i];
    }
    //
    vector<vector<int>> A(N, vector<int>(M));

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> A[i][j] ;
        }
    }
    //
    int cnt=0;
    long long total=0;
    for(int i=0;i<N;i++){
        total =0;
        for(int j=0;j<M;j++){
            total = total + A[i][j]*B[j];
        }
        total = total + C;
        if(total > 0){
            cnt++;
        }
    }
    cout << cnt << endl;
}