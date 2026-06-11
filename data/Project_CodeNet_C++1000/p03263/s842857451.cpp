#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,w;
    cin >> h >> w;

    vector<vector<int>> a(h,vector<int>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }

    bool move = false;
    vector<int> xs;
    vector<int> ys;
    vector<int> xe;
    vector<int> ye;

    for (int i = 0; i < h; i++)
    {
        if(i % 2 == 0)
        {
            for (int j = 0; j < w; j++)
            {
                if(move)
                {
                    xe.push_back(j + 1);
                    ye.push_back(i + 1);
                    a[i][j] += move;
                }
                if(a[i][j] % 2 == 1)
                {
                    xs.push_back(j + 1);
                    ys.push_back(i + 1);
                    move = true;
                }
                else
                {
                    move = false;
                }
            }
        }
        else
        {
            for (int j = w - 1; j >= 0; j--)
            {
                if(move)
                {
                    xe.push_back(j + 1);
                    ye.push_back(i + 1);
                }
                a[i][j] += move;
                if(a[i][j] % 2 == 1)
                {
                    xs.push_back(j + 1);
                    ys.push_back(i + 1);
                    move = true;
                }
                else
                {
                    move = false;
                }
            }
        }
    }

    //cout << ys.size() << " " << xs.size() << " " << ye.size() << " " << xe.size() << " " << endl;

    int mini_size = min(ys.size(), min(ye.size(), min(xe.size() , xs.size())));
    cout << mini_size << endl;
    for (int i = 0; i < mini_size; i++)
    {
        cout << ys[i] << " " << xs[i] << " " << ye[i] << " " << xe[i] << endl;
    }
    
}
