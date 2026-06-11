#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int ans = 0;
    //cout << (5-2)/2 << endl;
    vector<int> x(3);
    for (int i = 0; i < 3; ++i)
        cin >> x[i];
    sort(x.begin(), x.end());
    if (x[0] % 2 == 0 && x[1] % 2 == 0 && x[2] % 2 == 0)
    {
        ans += (x[2] - x[1]) / 2;
        ans += (x[2] - x[0]) / 2;
        cout << ans << endl;
        return 0;
    }
    else if (x[0] % 2 == 1 && x[1] % 2 == 1 && x[2] % 2 == 1)
    {
        ans += (x[2] - x[1]) / 2;
        ans += (x[2] - x[0]) / 2;
        cout << ans << endl;
        return 0;
    }

    ans += (x[2] - x[1]) / 2;
    x[1] += ans * 2;

    int y= (x[2] - x[0]) / 2;
    ans += y;
    x[0] += y * 2;

    sort(x.begin(), x.end());

    if(x[0]==x[1]){
        ans++;
    }else{
        ans += 2;
    }

    cout << ans << endl;

    return 0;
}