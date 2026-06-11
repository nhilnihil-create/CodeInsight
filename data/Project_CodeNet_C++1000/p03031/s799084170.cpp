#include <bits/stdc++.h>
using namespace std;

int count_lighting_bulb(int M, const vector<int> &p_vec, 
        const vector<bitset<10>> &connected, const bitset<10> &switches)
{
    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        int num_valid_switches = (connected.at(i) & switches).count();
        if (num_valid_switches % 2 == p_vec.at(i))
            ++cnt;
    }
    return cnt;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> p_vec(M);
    vector<bitset<10>> connected(M, 0);
    int k, s;
    for (int i = 0; i < M; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> s;
            --s;
            connected.at(i).set(s);
        }
    }
    for (int i = 0; i < M; ++i)
        cin >> p_vec.at(i);
    int cnt = 0;
    for (int i = 0; i < (1 << N); ++i) {
        bitset<10> switches(i);
        int num = count_lighting_bulb(M, p_vec, connected, switches);
        if (num == M)
            ++cnt;
    }
    cout << cnt << endl;
}
