#include <bits/stdc++.h>
using namespace std;
int INF = 1e9+7;
using ll = long long;
using P = pair<int, int>;

void normalize(vector<P> &tmp)
{
    if(tmp.size() == 1) return;
    if(tmp.back().first == tmp[tmp.size()-2].first)
    {
        tmp[tmp.size()-2].second += tmp.back().second;
        tmp.pop_back();
    }
}

void updateLast(vector<P> &tmp)
{
    if(tmp.back().second == 1)
    {
        tmp.back().first++;
        normalize(tmp);
    }
    else
    {
        tmp.back().second--;
        tmp.push_back(P(tmp.back().first+1, 1));
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int lb = 0;
    int ub = n;

    while(ub - lb > 1)
    {
        int mid = (ub + lb) >> 1;
        vector<P> tmp;
        tmp.push_back(P(1, a[0]));
        bool flag = true;
        for(int i = 1; i < n; i++)
        {
            if(a[i] > a[i-1])
            {
                tmp.push_back(P(1, a[i]-a[i-1]));
                normalize(tmp);
            }
            else if(a[i] == a[i-1])
            {
                if(tmp.back().first != mid)
                {
                    updateLast(tmp);
                }
                else
                {
                    int size = tmp.back().second;
                    tmp.pop_back();
                    if(tmp.size() == 0)
                    {
                        flag = false;
                        break;
                    }
                    updateLast(tmp);
                    tmp.push_back(P(1, size));
                }
            }
            else
            {
                int diff = a[i-1] - a[i];
                int sum = 0;
                while(sum + tmp.back().second < diff)
                {
                    sum += tmp.back().second;
                    tmp.pop_back();
                }
                int dsize = diff - sum;
                if(dsize == tmp.back().second)
                {
                    tmp.pop_back();
                }
                else
                {
                    tmp.back().second -= dsize;
                }
                if(tmp.back().first != mid)
                {
                    updateLast(tmp);
                }
                else
                {
                    int size = tmp.back().second;
                    tmp.pop_back();
                    if(tmp.size() == 0)
                    {
                        flag = false;
                        break;
                    }
                    updateLast(tmp);
                    tmp.push_back(P(1, size));
                }
            }
        }
        if(flag) ub = mid;
        else lb = mid;
    }
    cout << ub << endl;
}
