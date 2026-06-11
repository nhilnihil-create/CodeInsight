#include<bits/stdc++.h>
using namespace std;
const long long INF = (long long)1 << 60;

struct cake
{
    long long x, y, z;
};


int main() {
    int N, M;
    cin >> N >> M;
    vector<cake> input;
    for (size_t i = 0; i < N; i++)
    {
        cake c;
        cin >> c.x >> c.y >> c.z;
        input.push_back(c);
    }

    long long d[N];
    long long ans = -INF;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < N; j++)
        {
            d[j] = 0;
            if(i & 1) d[j] += input[j].x;
            else d[j] -= input[j].x;
            if(i & 2) d[j] += input[j].y;
            else d[j] -= input[j].y;
            if(i & 4) d[j] += input[j].z;
            else d[j] -= input[j].z;
        }
        sort(d, d + N);
        long long tmp = 0;
        for (int j = 0; j < M; j++)
        {
            tmp += d[N - 1 - j];
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}