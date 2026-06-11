#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<int> values(N);
    rep(i, 0, N) cin >> values[i];
    sort(values.begin(), values.end());

    int diff = 12;
    rep(s, 0, 2)
    {
        int prev = 0;
        for (int i=s; i<N; i+=2)
        {
            diff = min(diff, values[i]-prev);
            prev = values[i];
        }
    }
    if (N>1)
        diff = min(diff, 24-values[N-1]-values[N-2]);

    cout << diff << endl;
    return 0;
}