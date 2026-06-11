#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> map(501, vector<int> (501, 0));
    // vector<int> l(m);
    // vector<int> r(m);
    vector<int> res(q);
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        map.at(x).at(y)++;
    }
    vector<vector<int>> add(501, vector<int> (501, 0));
    for(int i = 1; i < 501; i++){// 和を求めておく
        for(int j = 1; j < 501; j++){
            add.at(i).at(j) = map.at(i).at(j) + add.at(i).at(j - 1);
        }
    }
    /*
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            cout << map.at(i).at(j);
            // cout << add.at(i).at(j);
        }
        cout << endl;
    }
    cout << endl;
    */
    /*for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            // cout << map.at(i).at(j);
            cout << add.at(i).at(j);
        }
        cout << endl;
    }*/
    
    int sum = 0;
    for(int i = 0; i < q; i++){
        sum = 0;
        cin >> x >> y;
        for(int j = x; j < 501; j++){
            sum += add.at(j).at(y);
        }
        /* for(int j = x; j < n + 1; j++){
            for(int k = 0; k <= y; k++){
                sum += map.at(j).at(k);
            }
        }*/
        // cout << sum << endl;
        res.at(i) = sum;
    }

    for(int i = 0; i < q; i++){
        cout << res.at(i) << endl;
    }

}