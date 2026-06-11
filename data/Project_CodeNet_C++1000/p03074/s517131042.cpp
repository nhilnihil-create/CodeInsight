#include <bits/stdc++.h>

using namespace std;


template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s)
{
    return '"' + s + '"';
}

string to_string(const char* s)
{
    return to_string((string) s);
}

string to_string(bool b)
{
    return (b ? "true" : "false");
}

string to_string(vector<bool> v)
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; i++)
    {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p)
{
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p)
{
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out()
{
    cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const long long INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int i = 0;
    vector<int> a;
    while (i < n)
    {
        int cur = 0;
        if (s[i] == '1')
        {
            while (i < n && s[i] == '1')
            {
                cur++;
                i++;
            }
        }
        else
        {
            while (i < n && s[i] == '0')
            {
                cur--;
                i++;
            }
        }
        a.push_back(cur);
    }
    i = 0;
    queue<int> que;
    int len = 0;
    int w = 0;
    int ans = 0;
    while (i < (int)a.size())
    {
        if (a[i] > 0)
        {
            len += a[i];
            que.push(a[i]);
        }
        else
        {
            if (w == k)
            {
                if (que.front() > 0)
                {
                    len -= que.front();
                    que.pop();
                }
                if (que.front() < 0)
                {
                    len += que.front();
                    que.pop();
                }
                w--;
            }

            w++;
            len -= a[i];
            que.push(a[i]);
        }
        i++;
        ans = max(ans, len);
    }
    cout << ans;
    return 0;
}

