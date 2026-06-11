#include <bits/stdc++.h>

#define MAX_N 1000

#define MAX_LOG 30

using namespace std;

typedef long long lint;

const int dl[] = {-1, 1, 0 , 0};
const int dc[] = {0, 0, -1, 1};
const char chr[] = {'L', 'R', 'D', 'U'};

int n;

struct elem
{
    lint x, y;
};

elem v[MAX_N + 1];

int ap[2];

lint p[MAX_LOG + 2 + 1];
int k;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> v[i].x >> v[i].y;
        ap[(v[i].x + v[i].y) & 1] ++;
    }

    if((ap[0] ^ ap[1]) != max(ap[0], ap[1]))
    {
        cout << "-1\n";

        exit(0);
    }

    if(ap[0] != 0)
        p[++ k] = 1;

    for(int i = 0; i <= MAX_LOG; i ++)
        p[++ k] = (1 << i);

    cout << k << "\n";
    for(int i = 1; i <= k; i ++)
        cout << p[i] << " " ;
    cout << "\n";

    for(int i = 1; i <= n; i ++)
    {
        lint cx = 0;
        lint cy = 0;
        string rez;
        rez.clear();
        rez.resize(k);

      //  cout << "SUNTEM " << i <<  " KK " << k << "\n";

        for(int d = k; d >= 1; d --)
        {
           // cout << "SUNTEM " << cx << " Y " << cy << "\n";

            lint dx = 0;
            lint dy = 0;
            lint cr = -1;
            lint mn = (1LL << 60);
            for(int dir = 0; dir < 4; dir ++)
            {
                lint ux = cx + dl[dir] * p[d];
                lint uy = cy + dc[dir] * p[d];

                lint dist = abs(v[i].x - ux) + abs(v[i].y - uy);

               // if(i == 2 && d == k)
              //      cout << ux << " *** " << uy << " DIST TOT " << dist << "\n";

                if(dist < mn)
                {
                    mn = dist;

                    cr = dir;
                    dx = dl[dir];
                    dy = dc[dir];
                }
            }

            rez[d - 1] = chr[cr];
            cx = cx + dx * p[d];
            cy = cy + dy * p[d];
        }
       // cout << "SUNTEM FINAL " << cx << " Y " << cy << "\n";

        cout << rez << "\n";
    }

    return 0;
}
