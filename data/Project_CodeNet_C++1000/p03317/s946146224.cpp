#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    --k;
    int idx = 0;
    int num = 100001;
    for(int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        if(t < num)
        {
            idx = i;
            num = t;
        }
    }

    int l = idx;
    int r = n-idx-1;
    int ans = l/k + r/k;
    ans += ceil((l%k+r%k)/(double)k);

    cout << ans << endl;
}