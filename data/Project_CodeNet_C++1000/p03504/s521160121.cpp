#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N, C; cin >> N >> C;
    struct Program
    {
        int S; int T; int C;
        const bool operator<(const Program &rhs)
        {
            if (S != rhs.S) return S < rhs.S;
            else return C < rhs.C;
        }
    };
    map<int, vector<pair<int, int>>> C2SandTMap;
    for (int i = 0; i < N; ++i)
    {
        int si, ti, ci; cin >> si >> ti >> ci;
        C2SandTMap[ci].push_back({ si, ti });
    }
    // 同じチャンネルで，ti = sjとなるものは必ず連続して撮る方が最適
    vector<Program> programs;
    for (int c = 1; c <= C; ++c)
    {
        if (C2SandTMap.find(c) != C2SandTMap.end())
        {
            auto STpairs = C2SandTMap[c];
            sort(STpairs.begin(), STpairs.end());
            int pairNum = static_cast<int>(STpairs.size());
            int si = STpairs[0].first, ti = STpairs[0].second;
            for (int j = 1; j < pairNum; ++j)
            {
                if (ti == STpairs[j].first)
                {
                    ti = STpairs[j].second;
                }
                else
                {
                    programs.push_back({ si, ti, c });
                    si = STpairs[j].first;
                    ti = STpairs[j].second;
                }
            }
            programs.push_back({ si, ti, c });
        }
    }
    sort(programs.begin(), programs.end());
    // 開始時刻が早い順に積んでいく
    multiset<int> endTimeSet;   //  終了時刻が早い順にソートしておく
    endTimeSet.insert(-programs.front().T); // upper_boundを降順で使うために-1を掛けておく
    int pNum = static_cast<int>(programs.size());
    for (int i = 1; i < pNum; ++i)
    {
        const int si = -programs[i].S;  // upper_boundを降順で使うために-1を掛けておく
        const int ti = -programs[i].T;  // upper_boundを降順で使うために-1を掛けておく
        auto itr = upper_bound(endTimeSet.begin(), endTimeSet.end(), si);
        if (itr == endTimeSet.end())
        {
            endTimeSet.insert(ti);
        }
        else
        {
            endTimeSet.erase(itr);
            endTimeSet.insert(ti);
        }
    }
    int ans = static_cast<int>(endTimeSet.size());
    cout << ans << endl;
}
