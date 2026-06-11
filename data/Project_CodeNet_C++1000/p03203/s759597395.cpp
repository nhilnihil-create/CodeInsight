#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

typedef vector<pair<LL,LL>>   vect_LL_LL;
typedef vector<pair<int,int>> vect_i_i;

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    if (p1.first != p2.first)
        return p2.first > p1.first;
    else
        return p2.second > p1.second;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W, N;
    scanf("%d %d %d", &H, &W, &N);
    int x, y;
    vect_i_i obstacles;

    for (int i=0; i<N; i++)
    {
        scanf("%d %d", &x, &y);
        if (x >= y)
            obstacles.push_back({x, y});
    }
    sort(obstacles.begin(), obstacles.end(), compare);

    int offset = 0;
    for (int i = 0; i < obstacles.size();i++)
    {

        if (obstacles[i].first > obstacles[i].second + offset)
        {
            printf("%d\n", obstacles[i].first - 1);
            return 0;
        }
        else if (obstacles[i].first == obstacles[i].second + offset)
            offset++;
    }
    printf("%d\n", H);
    return 0;
}
