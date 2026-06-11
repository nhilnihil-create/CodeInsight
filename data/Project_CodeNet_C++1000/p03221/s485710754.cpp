#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    vector<int> p(M,0);
    vector<int> yp(M,0);
    vector<vector<int>> y(N,vector<int>(0,0));

    for (int i = 0; i < M; ++i)
    {
        int tmp_p, tmp_y;
        cin >> tmp_p >> tmp_y;
        --tmp_p;
        p[i] = tmp_p;
        yp[i] = tmp_y;
        y[tmp_p].push_back(tmp_y);
    }

    for (int i = 0; i < N; ++i)
    {
        sort(y[i].begin(), y[i].end());
    }

    for (int i = 0; i < M; ++i)
    {
        int index = lower_bound(y[p[i]].begin(), y[p[i]].end(), yp[i]) - y[p[i]].begin();
        cout << setw(6) << std::setfill('0') << p[i]+1;
        cout << setw(6) << std::setfill('0') << index+1 << endl;   
    }
    



    return 0;
}

