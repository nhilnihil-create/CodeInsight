#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int N,M;
    map<ll, ll>D;
    map<ll, ll>T;
    cin >> N;
    rep(i, 0, N){
        ll tmp;
        cin >> tmp;
        D[tmp]++;
    }
    cin >> M;
    rep(i, 0, M){
        ll tmp;
        cin >> tmp;
        T[tmp]++;
    }
    for (auto &p : T){
        ll index = p.first;
        if(D[index]<p.second){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
