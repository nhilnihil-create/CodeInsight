#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    char s[h][w];
    rep(i, h)
    {
        rep(j, w)
        {
            scanf(" %c", &s[i][j]); //scanfするとき改行がある場合、" %c"とする
        }
    }
    int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
    int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    rep(i, h)
    {
        rep(j, w)
        {
            if (s[i][j] != '#')
            {
                int count = 0;
                rep(d, 8)
                {
                    int ni = i + dy[d];
                    int nj = j + dx[d];
                    if(ni < 0 || h <= ni) continue; //s[-1][*]やs[h以上][*]など表からはみ出す場合は除外する
                    if(nj < 0 || w <= nj) continue; //s[*][-1]やs[*][w以上]など表からはみ出す場合は除外する
                    if(s[ni][nj] == '#') count++;
                }
                printf("%d", count);
            }
            else printf("#");
        }
        printf("\n");
    }
    return 0;
}