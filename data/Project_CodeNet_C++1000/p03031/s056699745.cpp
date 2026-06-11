#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//cout << std::fixed << std::setprecision(15) << y << endl;

int main() {
    int n,m = 0;
    cin >> n >> m;
    vector<vector<int>> s(m,vector<int>(n));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            s[i][j] = 0;
        }
    }
    for(int i = 0;i < m;i++){
        int k = 0;
        cin >> k;
        for(int j = 0;j < k;j++){
            int tmp = 0;
            cin >> tmp;
            s[i][tmp - 1] = 1;
        }
    }
    //cout << endl;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            //cout << s[i][j] << " ";
        }
        //cout << endl;
    }
    
    vector<int> p(m);
    for(int i = 0;i < m;i++){
        cin >> p[i];
    }
    int cnt = 0;
    for(int i = 0;i < (1<<n);i++){
        vector<int> c(m);
        bool flag = false;
        for(int j = 0;j < m;j++){
            c[j] = 0;
        }
        for(int j = 0;j < n;j++){
            if(i & (1<<j)){
                for(int k = 0;k < m;k++){
                    if(s[k][j] == 1){
                        c[k] ++;
                    }
                }
            }
        }
        //cout << "c" << i << " ";
        for(int j = 0;j < m;j++){
            //cout << c[j] << " ";
        }
        //cout << endl;
        for(int j = 0;j < m;j++){
            if(c[j] % 2 == p[j]){
                flag = true;
            }else{
                flag = false;
                break;
            }
        }
        
        if(flag){
            //cout << "ok" << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}