#include <bits/stdc++.h>

using namespace std;
int m, k;
int main(){
    cin >> m >> k;
    if(m == 1 && k == 1){
        cout << -1;
        return 0;
    }
    if((1 << m) - 1 < k){
        cout << -1;
        return 0;
    }
    if(k == 0){
        for(int i = 0; i <= (1 << m) - 1; i++){
            cout << i << " " << i << " ";
        }
    }
    else{
        int l, r;
        vector < int > v;
        if(k % 4 == 0){
            l = k;
            r = k + 3;
            v.push_back(k + 1);
            v.push_back(k + 2);
            v.push_back(k + 3);
        }
        else if(k % 4 == 1){
            l = k - 1;
            r = k + 2;
            v.push_back(k - 1);
            v.push_back(k + 1);
            v.push_back(k + 2);
        }
        else if(k % 4 == 2){
            l = k - 2;
            r = k + 1;
            v.push_back(k - 2);
            v.push_back(k - 1);
            v.push_back(k + 1);
        }
        else{
            l = k - 3;
            r = k;
            v.push_back(k - 3);
            v.push_back(k - 2);
            v.push_back(k - 1);
        }
        for(int i = 0; i < l; i++){
            cout << i << " ";
        }
        for(int i = r + 1; i <= (1 << m) - 1; i++){
            cout << i << " ";
        }
        for(auto to : v){
            cout << to << " ";
        }
        cout << k << " ";
        reverse(v.begin(), v.end());
        for(auto to : v){
            cout << to << " ";
        }
        for(int i = (1 << m) - 1; i > r; i--){
            cout << i << " ";
        }
        for(int i = l - 1; i >= 0; i--){
            cout << i << " ";
        }
        cout << k;
    }
}
