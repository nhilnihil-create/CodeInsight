#include <bits/stdc++.h>

typedef long long ll;
typedef long long ull;
//typedef ull com;
#define PI acos(-1)
#define endl '\n'
/**
1- Choose the smallest problem to solve first
2- Read the problem well
3- Test each point in the problem
4- Try the samples on the idea first before typing the code
5- Don't take too much time through one problem if you didn't read all the problems
6- Analyze the standings to pick up the optimal problem to solve
**/
using namespace std;
/**int n, *x, *y;
void _merge(int *l, int *r)
{
    int i, *l1 = l, *l2 = l + (r - l) / 2 + 1, *r1 = l + (r - l) / 2, *r2 = r;
    for(i = l - x; l1 <= r1 && l2 <= r2; i++)
        if(*l2 < *l1)
            y[i] = *l2++;
        else
            y[i] = *l1++;
    while(l1 <= r1)y[i++] = *l1++;
    while(l2 <= r2)y[i++] = *l2++;
    for(int i = l - x, *j = l; j <= r; i++, j++)
        *j = y[i];
}
void merge_sort(int *l, int *r)
{
    if(r <= l)
        return;
    merge_sort(l, l + (r - l) / 2);
    merge_sort(l + (r - l) / 2 + 1, r);
    _merge(l, r);
}**/
/**struct Int
{
    int first, second;
    Int(int st = 0, int nd = 0): first(st), second(nd){}
    bool operator<(const Int other) const
    {
        if(first != other.first)
            return first > other.first;
        else return second < other.second;
    }
};**/

int main()
{
    cin.tie(NULL); cout.tie(NULL);  ios_base::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    /**int l, g, *ch, ans;
    pair<int, int> x;
    bool ok;
    Int tmp;
    priority_queue<Int> y, z;
    while(cin >> l >> g)
    {
        if(!l && !g)
            break;
        ans = 0;
        for(int i = 0; i < g; i++)
        {
            cin >> x.first >> x.second;
            y.push(Int(max(0, x.first - x.second), min(l, x.first + x.second)));
        }
        while(!y.empty())
        {
            tmp = y.top();
            y.pop();
            if(!y.empty() && y.top().first >= tmp.first && y.top().second <= tmp.second)
            {
                y.pop();
                ans++;
                y.push(tmp);
            }
            else if(!y.empty() && y.top().first <= tmp.second)
            {
                tmp.second = y.top().second;
                y.pop();
                y.push(tmp);
            }
            else
                z.push(tmp);
        }
        ch = new int[l + 1];
        for(int i = 0; i <= l; i++)
            ch[i] = 0;
        while(!z.empty())
        {
            ch[z.top().first]++;
            ch[z.top().second + 1]--;
            z.pop();
        }
        for(int i = 1; i <= l; i++)
            ch[i] += ch[i - 1];
        for(int i = 0; ok && i < l; i++)
            if(!ch[i])
                ok = 0;
        if(ok)
            cout << ans;
        else
            cout << -1;
        cout << endl;
        delete[] ch;
    }**/
    /**
    int n, x[4]{0}, tmp, sum = 0;
    vector<int> u(1, 1);
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
        {
            u.push_back(i);
            if(i * i != n)
                u.push_back(n / i);
        }
    sort(u.begin(), u.end());
    tmp = *(lower_bound(u.begin(), u.end(), int(sqrt(n))))
    for(int i = 0; i < 4; i++)
        x[i] = tmp;
    sum = tmp * 4;
    if(sum < n)
        for(int i = u.size() - 1; i >= 0; i--)
        {

        }**/
    int n, *a, *b, ans = 0, *cnt, *tmp[4];
    cin >> n;
    a = new int[n];
    b = new int[n];
    cnt = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[i] = 0;
    }
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 28; i >= 0; i--)
    {
        for(int j = 0; j < n; j++)
        {
            a[j] %= (1 << (i + 1));
            b[j] %= (1 << (i + 1));
        }
        sort(b, b + n);
        for(int j = 0; j < n; j++)
        {
            tmp[0] = lower_bound(b, b + n, (3 << i) - a[j]);
            tmp[1] = upper_bound(b, b + n, (1 << (i + 2)) - 2 - a[j]);
            tmp[2] = lower_bound(b, b + n, (1 << i) - a[j]);
            tmp[3] = upper_bound(b, b + n, (1 << (i + 1)) - 1 - a[j]);
            if((tmp[1] - tmp[0] + tmp[3] - tmp[2]) & 1)
                cnt[j] |= (1 << i);
        }
    }
    for(int i = 0; i < n; i++)
        ans ^= cnt[i];
    cout << ans;

}
