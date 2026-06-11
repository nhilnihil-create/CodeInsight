#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;

    pair<int, int> p[q];
    for(int i = 0; i < q; i++){
        cin >> p[i].first >> p[i].second;
    }

    int flag[100001];
    int c[100001];
    for(int i = 0; i < 100001; i++){
        flag[i] = 0;
        c[i] = 0;
    }
    for(int i = 2; i < 100001; i++){
        if(flag[i] == 0){
            for(int j = i + i; j < 100001; j += i){
                flag[j] = 1;
            }
        }
    }
    for(int i = 3; i < 100001; i += 2){
        if(flag[i] == 0 && flag[(i + 1) / 2] == 0){
            c[i]++;
        }
    }
    for(int i = 3; i < 100001; i++){
        c[i] += c[i - 1];
    }

    for(int i = 0; i < q; i++){
        cout << c[p[i].second] - c[p[i].first - 1] << endl;
    }
}