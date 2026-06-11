#include<bits/stdc++.h>


int main(void) {
    using namespace std;

    long n;
    cin >> n;

    vector<pair<long,long>> r;
    if(n % 2) {
        vector<vector<long>> a;

        a.push_back({n});

        for(int i=1; i<=(n-1)/2; i++)
            a.push_back({i, n-i});

        for(int i=0; i<a.size(); i++)
            for(int j=i+1; j<a.size(); j++)
                for(auto x: a[i])
                    for(auto y: a[j])
                        r.push_back({x, y});

    } else {
        vector<vector<long>> a;

        for(int i=1; i<=n/2; i++)
            a.push_back({i, n-i+1});

        for(int i=0; i<a.size(); i++)
            for(int j=i+1; j<a.size(); j++)
                for(auto x: a[i])
                    for(auto y: a[j])
                r.push_back({x, y});
    }

    cout << r.size() << endl;
    for(auto &t: r)
        cout << t.first << ' ' << t.second << endl;

    return 0;
}
