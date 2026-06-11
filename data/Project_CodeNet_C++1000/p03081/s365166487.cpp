#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <list>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <random>
#include <queue>
#include <fstream>
#include <iterator> // std::back_inserter
#include <chrono>
#include <string>

using namespace std;

int N, Q;
vector<pair<char, char>> spel;
vector<char> mp;

int check_over(int n)
{
    int now = n;

    for (unsigned int i = 0; i < spel.size(); i++)
    {
        if (mp[now] == spel[i].first)
        {
            if (spel[i].second == 'R')
                now += 1;
            else
                now -= 1;

            if (now == -1)
                break;
            if (now == N)
                break;
        }
    }

    return now;
}

int main(int argc, char *argv[])
{

    cin >> N >> Q;

    char a, b;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        mp.push_back(a);
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> a >> b;
        spel.push_back(make_pair(a, b));
    }

    int c, d, d2 = 1;
    d = 1;

    int n = -1, m = N;

    while (n + 1 < m)
    {
        c = (n + m) / 2;
        d = check_over(c);
        if (d == -1)
            n = c;
        else 
            m = c;
    }

    c = m;

    int c2;

    n = -1;
    m = N;

    while (n + 1 < m)
    {
        c2 = (n + m) / 2;
        d = check_over(c2);
        if (d == N)
            m = (n + m) / 2;
        else
            n = (n + m) / 2;
    }
    c2 = m;

    int ans;

    ans = N - c - (N - c2);
    cout << ans;

    return 0;
}