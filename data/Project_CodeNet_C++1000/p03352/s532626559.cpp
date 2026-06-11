#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int X;
    cin >> X;

    int ans = 1;
    if (X == 1)
    {
        cout << ans << endl;
        return 0;
    }
    
    for (int i = 2; i * i<= X; i++)
    {
        int count = 0;
        int temp = X;
        while (temp / i > 0)
        {
            count++;
            temp /= i;
        }
        cerr << "i=" << i << " count=" << count << endl;
        ans = max(ans, (int)pow(i, count));
        
    }
    
    cout << ans << endl;
  return 0;
}