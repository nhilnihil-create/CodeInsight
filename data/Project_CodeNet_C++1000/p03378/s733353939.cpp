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
typedef long long ll;
int main() {
    int N,M,X;
    cin >> N >> M >> X;
    //
    vector<int> A(M);
    vector<int> B(N+1);   // 料金を格納
    for(int i=0;i<=N;i++){
        B[i]=0;
    }
    for(int i=0;i<M;i++){
        cin >> A[i];
        B[A[i]]=1;
    }
    //
    vector<int> cost(N+1); 
    cost[X]=0;
    // to N
    for(int i=X+1;i<=N;i++){
        cost[i] = cost[i-1] + B[i];
    }
    // to 0
    for(int i=X-1;i>=0;i--){
        cost[i] = cost[i+1] + B[i];
    }
    int min_cost;
    min_cost = min(cost[0],cost[N]); 
    cout << min_cost << endl;
}