#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , m;

int main()
{
    _FastIO;
    cin >> n >> m;
    vector<int> v;
    for(int i = 1; i * i < m; i++){
        if(m % i == 0){
            v.push_back(i);
            v.push_back(m / i);
        }
    }
    if(floor(sqrt(m)) == ceil(sqrt(m))){
        v.push_back(int(sqrt(m)));
    }
    sort(v.begin() , v.end());
    reverse(v.begin() , v.end());
    for(int i = 0; i < v.size(); i++){
        int k = m / v[i];
        if(n <= k){
            cout << v[i] << endl;
            return 0;
        }
    }
    cout << "1" << endl;
    return 0;
}
