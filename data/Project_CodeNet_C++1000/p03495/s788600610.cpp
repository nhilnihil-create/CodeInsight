#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        m[A]++;
    }

    int s = m.size();
    vector<int> v(s);
    int j = 0;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        v.at(j) = i->second;
        j++;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < s - K; i++)
    {
        cnt += v.at(i);
    }
    cout << cnt << endl;
}
