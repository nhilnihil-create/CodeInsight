#include<iostream>
#include<vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> digit(int num, int n){
    vector<int> v(n, 0);
    for(int i =0 ; i < n; i++){
        v[i] = num%2;
        num /= 2;
    }
    return v;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        v.push_back(vector<int>(k));
        for(int j = 0; j < k; j++){
            cin >> v[i][j];
        }
    }
    vector<int> p(m);
    for(int i = 0; i < m; i++) cin >> p[i];


    int ans = 0;
    int po = pow(2, n);
    for(int num = 0; num < po; num++){
        vector<int> d = digit(num, n);

        /*for(int i : d) cout << i;
        cout << endl;*/

        int light_num = 0;
        for(int i = 0; i < m; i++){
            int on_num = 0;
            for(int j = 0; j < v[i].size(); j++){
                on_num += d[v[i][j]-1];
            }
            //cout << on_num << endl;
            if(on_num%2 == p[i]) light_num++;
        }
        if(light_num == m) ans++;
        //cout << endl;
    }

    cout << ans << endl;

}