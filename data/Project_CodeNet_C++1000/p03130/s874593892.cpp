#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    V<int> v;
    for(int i = 0; i < 3; i++){
        int a, b; cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
    }

    sort(ALL(v));

    if(v[1] != v[2] || v[3] != v[4]){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }


    return 0;
}
