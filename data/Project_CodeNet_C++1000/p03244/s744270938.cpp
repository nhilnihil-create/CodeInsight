#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> odd(n/2), even(n/2);
    map<int, int> o;
    map<int, int> e;
    for(int i = 0; i < n/2; i++){
        cin >> odd.at(i) >> even.at(i);
        o[odd.at(i)]++; e[even.at(i)]++;
    }
    int o1, o2, e1, e2;
    int key_o, value_o, key_e, value_e;
    int cnt = 0;
    for(auto nv: o){
        if(cnt < nv.second){
            cnt = nv.second;
            key_o = nv.first;
        }
    }
    o1 = cnt;
    cnt = 0;
    for(auto nv: o){
        if(key_o != nv.first && cnt < nv.second){
            cnt = nv.second;
        }
    }
    o2 = cnt;
     for(auto nv: e){
        if(cnt < nv.second){
            cnt = nv.second;
            key_e = nv.first;
        }
    }
    e1 = cnt;
    cnt = 0;
    for(auto nv: e){
        if(key_e != nv.first && cnt < nv.second){
            cnt = nv.second;
        }
    }
    e2 = cnt;
    if(key_o != key_e) cout << n - e1 - o1 << endl;
    else cout << min(n - e1 - o2, n - e2 - o1);
}