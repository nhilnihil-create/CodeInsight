#include <bits/stdc++.h>
using namespace std;

string s;
int x, y;

short a[4010][2][8010];

vector<int> ido[2];

bool dp1(int i, int j){
    if(i == ido[0].size()){
        if(j == x){
            return true;
        }
        return false;
    }

    if(a[i][j >= 0][abs(j)] != -1){
        return a[i][j >= 0][abs(j)];
    }

    if(i == 0){
        return a[i][j >= 0][abs(j)] = dp1(i+1, j+ido[0][i]);
    }else{
        return a[i][j >= 0][abs(j)] = dp1(i+1, j+ido[0][i]) || dp1(i+1, j-ido[0][i]);
    }
}

bool dp2(int i, int j){
    if(i == ido[1].size()){
        if(j == y){
            return true;
        }
        return false;
    }

    if(a[i][j >= 0][abs(j)] != -1){
        return a[i][j >= 0][abs(j)];
    }

    return a[i][j >= 0][abs(j)] = dp2(i+1, j+ido[1][i]) || dp2(i+1, j-ido[1][i]);
}

int main(){
    cin >> s;
    cin >> x >> y;

    int tmp = 0;
    int nakamura = 0;

    for(int i = 0;i < s.size();i++){
        if(s[i] == 'F'){
            tmp++;
        }else{
            ido[nakamura].push_back(tmp);
            nakamura = (nakamura + 1) & 1;
            tmp = 0;
        }
    }

    ido[nakamura].push_back(tmp);

    memset(a, -1, sizeof(a));
    if(dp1(0, 0)){
        memset(a, -1, sizeof(a));
        if(dp2(0, 0)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        cout << "No" << endl;
    }

    return 0;
}
