#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(),x.end()

#define pb  emplace_back
#define X   first
#define Y   second

const int   N   = 2e5 + 5;

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;
    ll  S = 0;

    bool equal = 1;
    vector<int> vec;

    for(int i = 0 ; i < n ; ++i)    {
        int x;  cin >> x;
        int y;  cin >> y;

        if (x != y) equal = 0;
        if (x == y) S += x;
        else    {
            if (x < y)  S += y;
            else        vec.pb(y);
        }
    }
    if (vec.size()) {
        vec.erase(min_element(all(vec)));
        S += accumulate(all(vec),0ll);
    }
    if (equal)  S = 0;
    
    cout << S << endl;
}