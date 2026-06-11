#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int N;
    cin >> N;
    vector<tuple<string,int,int>> SPN;
    for(int i = 0; i < N; i++){
        string s;
        int point;
        int num;
        cin >> s >> point;
        point = -point;
        num = i + 1;
        SPN.emplace_back(s, point, num);
    }
    sort(all(SPN));
    for(auto x : SPN){
        cout << get<2>(x) << endl;
    }
}
