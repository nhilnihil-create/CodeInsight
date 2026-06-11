#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> connection(M, vector<int>(0));
    for (int i=0; i<M; i++)
    {
        int k;
        cin >> k;
        for (int j=0; j<k; j++)
        {
            int s;
            cin >> s;
            s--;
            connection[i].push_back(s);
        }
    }
    
    vector<int> amari(M);
    for (int i=0; i<M; i++) cin >> amari[i];

    int ans = 0;
    for (int i=0; i<(1<<N); i++)
    {
        bool all_bright=true;
        for (int j=0; j<M; j++)
        {
            int on_switch_num=0;
            for (int k=0; k<connection[j].size(); k++)
            {
                if (i&(1<<connection[j][k])) on_switch_num++;
            }
            if (on_switch_num%2 != amari[j]) all_bright=false;
            if (!all_bright) break;
        }
        if (all_bright) ans++;
    }
    cout << ans << endl;
}