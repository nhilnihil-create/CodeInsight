#include <bits/stdc++.h>
using namespace std;

void debug_vector(vector<int>& v){
    int n = v.size();
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;
    int ans = 0;
    vector<vector<int>> red, blue;
    vector<int> tmp;
    int a, b;    
    for (int i = 0; i < N; i++){
        cin >> a >> b;
        tmp.push_back(a);
        tmp.push_back(b);
        red.push_back(tmp);
        tmp.clear();
    }
    for (int i = 0 ; i < N; i++){
        cin >> a >> b;
        tmp.push_back(a);
        tmp.push_back(b);
        blue.push_back(tmp);

        tmp.clear();
    }
    // 赤点の x 座標が最も大きいところから見ていく．
    // そして対応させる青点は y 座標が最小を選んでいく．
    sort(red.begin(), red.end());
    for (int i = N - 1; i > - 1; i--){
        sort(blue.begin(),blue.end(),[](const vector<int> &alpha,const vector<int> &beta){return alpha[1] < beta[1];});
        for (int j = 0; j < blue.size(); j++){
            if (red[i][0] < blue[j][0] && red[i][1] < blue[j][1]){
                // cout << red[i][0] << " " << red[i][1] << " " << blue[j][0] << " " << blue[j][1] << endl;
                ans++;
                blue.erase(blue.begin() + j);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}