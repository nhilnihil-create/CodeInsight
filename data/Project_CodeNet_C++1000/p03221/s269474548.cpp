#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pys(M);
    for(int i=0; i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        pys.at(i) = make_pair(a, b);
    }

    vector<tuple<int, int, int>> ts;
    for(int i=0; i<M; i++)
    {
        ts.emplace_back(pys[i].first, pys[i].second, i);
    }

    sort(ts.begin(), ts.end());
    int prep = -1;
    int num = 1;
    for(auto &t : ts)
    {
        if(get<0>(t) != prep)
        {
            prep = get<0>(t);
            num = 1;
            get<1>(t) = num;
        }
        else
        {
            num++;
            get<1>(t) = num;
        }
    }

    auto comp = [](const tuple<int, int, int> &a, const tuple<int, int, int> &b){
        return get<2>(a) < get<2>(b);
    };
    sort(ts.begin(), ts.end(), comp);
    for(auto &t : ts)
    {
        cout << setfill('0') << setw(6) << get<0>(t) << setfill('0') << setw(6) << get<1>(t) << endl;
    }


    return 0;
}
