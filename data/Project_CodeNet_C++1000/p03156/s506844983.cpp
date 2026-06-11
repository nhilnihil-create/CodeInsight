#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> v(3);
    rep(i,n) {
        int p;
        cin >> p;
        if(p <= a) v[0]++;
        else if(p <= b) v[1]++;
        else v[2]++;
    }
    cout << *min_element(v.begin(),v.end()) << endl;
    return 0;
}
