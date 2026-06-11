#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair

using namespace std;

int n, a, b, u[1000001];

int main()
{
    cin >> n >> a >> b;

    if(a == 1)
    {
        if(b == n)
        {
            for(int i = n; i >= 1; i--)
                cout << i << " ";
        }else
        {
            cout << -1;
        }
        return 0;
    }
    if(b == 1)
    {
        if(a == n)
        {
            for(int i = 1; i <= n; i++)
                cout << i << " ";
        }else
        {
            cout << -1;
        }
        return 0;
    }

    if(a + b - 1 > n || a == 0 || b == 0)
    {
        cout << -1;
        return 0;
    }
    vector<int> vec, ans;
    int t = 0;
    if(a > b)
        t = 1, swap(a, b);

    for(int i = n; i >= 1; i--)
        vec.push_back(i);

    int l = 0, r = vec.size() - 1, kol1 = 0, kol2 = 0;
    while(ans.size() < n && a > 0 && b > 0)
    {
        int y = vec.size();
        for(int j = min(l + a - 1, y - 1); j >= l; j--)
        {
            if(u[vec[j]] == 0)
                ans.push_back(vec[j]);
            u[vec[j]] = 1;
        }

        l += a;
        b--;
        if(ans.size() >= n || b <= 0)
            break;

        for(int j = max(0, r - b + 1); j <= r; j++)
        {
                if(u[vec[j]] == 0)
                    ans.push_back(vec[j]);
                u[vec[j]] = 1;
        }
        r -= b;
        a--;
    }
    if(ans.size() != n)
    {
        cout << -1;
        return 0;
    }
    //cout << kol1 << " " << kol2 << endl;
    if(t == 1)
    {
        //cout << "*";
        for(int i = 0; i < ans.size(); i++)
            ans[i] = n - ans[i] + 1;
        //swap(kol1, kol2);
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
