#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int r; cin >> r;

    if(r < 1200){
        cout << "ABC" << endl;
        return 0;
    }

    if(r < 2800){
        cout << "ARC" << endl;
        return 0;
    }

    cout << "AGC" << endl;
}

