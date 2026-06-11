#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  	int N, X;
    cin >> N >> X;
    vector<int> G(N);
    for (int i=0; i<N; i++){
      	cin >> G[i];
    }
    sort(G.begin(), G.end());
    int SUM=0;
    for (int i=0; i<N; i++){
      	SUM += G[i];
    }
    int REST=X-SUM;
    cout << N+REST/G[0] << endl;
}