#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v(m);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        v[i] = {b,a};
    }
    sort(v.begin(),v.end());
    int end = v[0].first;
    int cnt = 1;

    for(int i = 1; i < m;i++){
        if (end <= v[i].second){
            cnt++;
            end = v[i].first;
        }
    }
    cout << cnt << endl;

    return 0;

}
