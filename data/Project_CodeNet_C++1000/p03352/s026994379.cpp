#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 10**9

int main() {
    vector<int> E;
    E.push_back(1);
    int x;
    cin >> x;
    for (int i=2;i<33;i++){
        for (int j=2;j<10;j++){
            if (pow(i,j)<=x){
                E.push_back(pow(i,j));
            }
            else {
                break;
            }
        }
    }
    int l = E.size();
    sort(all(E));
    cout << E.at(l-1) << endl;
}