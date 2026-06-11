#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        while (K--)
        {
            int A;
            cin >> A;
            --A;
            a[A]++;
        }
        
    }
    
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        if (a[i] == N)
        {
            ans++;
        }
        
    }
    
    cout << ans << endl;
  return 0;
}
