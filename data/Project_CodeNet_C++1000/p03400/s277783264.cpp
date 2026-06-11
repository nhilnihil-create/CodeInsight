#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, D, X;
    cin >> N >> D >> X;
    int sum = X;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        int j = 0;
        while (1 + j * A <= D)
        {
            sum++;
            j++;
        }
        
    }
    cout << sum << endl;    
    
    
  return 0;
}