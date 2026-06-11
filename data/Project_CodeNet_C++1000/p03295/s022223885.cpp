#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n, m, ans = 1;
    cin >> n >> m;
    vector<pair<int, int>> request;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        request.push_back(pair<int, int>(b, a));
    }

    sort(request.begin(), request.end());
    pair<int, int> p;
    int b_min = request[0].first;
    for(int i=0; i<m; i++){
        pair<int, int> p = request[i];
        if(p.second >= b_min){
          b_min = p.first;
          ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
