#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = 1<<29;
typedef long long ll;

int dp[100][2][100];//dp[keta][未満である][0でない数の個数]

struct UnionFind {
  vi parent;
  UnionFind(int N) : parent(N) {
    rep(i, N)parent[i] = i;
  }

  int getRoot(int child){
    return ((parent[child] == child) ? child : parent[child] = getRoot(parent[child]));
  }
  void unite(int x, int y){
    int root_x = getRoot(x);
    int root_y = getRoot(y);
    if(root_x == root_y)return;
    parent[root_x] = parent[root_y];
  }
  bool isSame(int x, int y){
    return getRoot(x) == getRoot(y);
  }
};
int main(){
    int N;cin >> N;
    int A, B;cin >> A >> B;
    int P[N];rep(i, N)cin >> P[i];
    int count1 = 0, count2 = 0, count3 = 0;
    rep(i, N){
        if(P[i] <= A)count1++;
        else if(P[i] <= B)count2++;
        else count3++;
    }
    cout << min(count1, min(count2, count3));
}
