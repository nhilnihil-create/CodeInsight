#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    int M = 0;
    cin >> M;
    int C = 0;
    cin >> C;
    vector<int> b(M);
    for(int i = 0; i < M; i++)
    {
    cin >> b.at(i);
    }
    int ansans = 0;
    int ans = 0;
    int t;
    for (size_t i = 0; i < N; i++)
    {
        ans = 0;
        for (size_t j = 0; j < M; j++)
        {
            cin >> t;
            ans += t*b.at(j);
        }
        if (ans + C > 0)
        {
            ansans++;
        }
        
        
    }
    cout << ansans << endl;
    
    

    return 0;
}