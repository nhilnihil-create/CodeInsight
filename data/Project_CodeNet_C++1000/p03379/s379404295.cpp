#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> xs(n+1);
    vector<int> vs(n+1);
    xs[0] = INT_MIN;
    vs[0] = INT_MIN;
    for(size_t i = 1; i <= n; ++i)
    {
        cin >>xs.at(i);
        vs.at(i) = xs.at(i);
    }
    sort(vs.begin(), vs.end());

    for(size_t i = 1; i <= n; ++i)
    {
        if(xs[i] > vs[(n+1)/2])
            cout << vs[n/2] << endl;
        else
            cout << vs[n/2+1] << endl;
    }

    return 0;
}
