#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void normalize(vector<P> &num)
{
    if(num.size() > 1)
    {
        if(num.back().first == num[num.size()-2].first)
        {
            num[num.size()-2].second += num.back().second;
            num.pop_back();
        }
    }
}
void inc(vector<P> &num)
{
    if(num.back().second == 1)
    {
        num.back().first++;
    }
    else
    {
        num.back().second--;
        num.push_back(P(num.back().first+1, 1));
    }
    normalize(num);
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll low = 0;
    ll high = n + 1;
    while(high - low > 1)
    {
        ll mid = (low + high) >> 1;
        bool ok = true;
        vector<P> num;
        num.push_back(P(0, a[0]));
        for(int i = 1; i < n; i++)
        {
            if(a[i] > a[i-1])
            {
                num.push_back(P(0, a[i]-a[i-1]));
            }
            else
            {
                ll sum = 0;
                while(sum + num.back().second <= a[i-1]-a[i])
                {
                    sum += num.back().second;
                    num.pop_back();
                }
                num.back().second -= a[i-1] - a[i] - sum;
                if(num.back().first == mid - 1)
                {
                    if(num.size() == 1)
                    {
                        ok = false;
                        break;
                    }
                    else
                    {
                        ll tmp = num.back().second;
                        num.pop_back();
                        inc(num);
                        num.push_back(P(0, tmp));
                    }
                }
                else
                {
                    inc(num);
                }
            }
            normalize(num);
        }
        if(ok) high = mid;
        else low = mid;
    }
    cout << high << endl;
}
