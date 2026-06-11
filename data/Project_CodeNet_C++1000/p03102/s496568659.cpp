#include <bits/stdc++.h>
using namespace std;
int n,m,c;
vector <int> b;
vector <vector<int>> avv;
bool isValid(int target){
    bool ret = false;
    int value = c;
    for(int i = 0; i < avv[target].size(); i++){
        value += b[i]*avv[target][i];
    }
    if(value>0)ret=true;
    return ret;
}
int main(){
    cin >> n >> m >> c;
    b = vector <int> (m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    avv = vector<vector<int>>(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        avv[i] = vector<int>(m);
        for(int j = 0; j < m; j++){
            cin >> avv[i][j];
        }
        if(isValid(i))ans++;
    }
    cout << ans << endl;
    #if 0
    cout << endl;
    for(int i = 0; i < m; i++){
        cout << b[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << avv[i][j] << " ";
        }
        cout << endl;
    }
    #endif
    return 0;
}