#include <bits/stdc++.h>
using namespace std;
void makeCombiUtil(vector<vector<int> >& ans, 
    vector<int>& tmp, int n, int left, int k) 
{ 
    // Pushing this vector to a vector of vector 
    if (k == 0) { 
        ans.push_back(tmp); 
        return; 
    } 
  
    // i iterates from left to n. First time 
    // left will be 1 
    for (int i = left; i <= n; ++i) 
    { 
        tmp.push_back(i); 
        makeCombiUtil(ans, tmp, n, i + 1, k - 1); 
  
        // Popping out last inserted element 
        // from the vector 
        tmp.pop_back(); 
    } 
} 

vector<vector<int> > makeCombi(int n, int k) 
{ 
    vector<vector<int> > ans; 
    vector<int> tmp; 
    makeCombiUtil(ans, tmp, n, 1, k); 
    return ans; 
} 
int main() {
  int c,N,C,answer=INT_MAX;
  cin >> N >> C;
  int D[C+1][C+1];
  for (int i = 1; i <= C; i++) {
    for (int j = 1; j <= C; j++) {
      cin >> D[i][j];
    }
  }
  vector<vector<int>> d(3,vector<int>(C+1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; d[(i+j)%3][c]++, j++) {
      cin >> c;
    }
  }
  for (auto p : makeCombi(C,3)) {
    do {
      int wrongness = 0;
      for (int c = 1; c <= C; c++) {
        wrongness += d[0][c]*D[c][p[0]];
        wrongness += d[1][c]*D[c][p[1]];
        wrongness += d[2][c]*D[c][p[2]];
      }
      answer = min(answer,wrongness);
    } while (next_permutation(p.begin(),p.end()));
  }
  cout << answer;
}