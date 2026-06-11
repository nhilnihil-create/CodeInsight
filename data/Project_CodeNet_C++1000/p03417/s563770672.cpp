#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
  
int main(){
    ll N, M;
    cin >> N >> M;
    if (N >= 2) N -= 2;
    if (M >= 2) M -= 2;
    cout << N * M << endl;
    return 0;
}