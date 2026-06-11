#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, k, l;
    int h, w; cin >> h >> w;
    int bom_count = 0;
    string board[h]; for (i=0; i<h; i++) cin >> board[i];

    for (i=0; i<h; i++)
    {
        for (j=0; j<w; j++)
        {
            if (board[i].at(j) == '.')
            {
                bom_count = 0;
                for (k=-1; k<=1; k++)
                {
                    for (l=-1; l<=1; l++)
                    {
                        if ((0<=(i+k) && (i+k)<h) && (0<=(j+l) && (j+l)<w))
                        {
                            if (board[i+k].at(j+l) == '#') bom_count++;
                        }
                    }
                }
                cout << bom_count;
            }
            else cout << '#';
        }
        cout << endl;
    }
}