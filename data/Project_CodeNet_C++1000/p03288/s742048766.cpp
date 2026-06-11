#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int r;
    cin >> r;

    if(r < 1200){
        cout << "ABC" << endl;
    }else if(r < 2800){
        cout << "ARC" << endl;
    }else{
        cout << "AGC" << endl;
    }

    return 0;
}
