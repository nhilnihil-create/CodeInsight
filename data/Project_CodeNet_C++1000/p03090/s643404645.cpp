#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int N;cin >> N;
    set<pair<int, int>> e;
    for(int i = 0;i < N-1;i++){
        for(int j = i + 1;j < N;j++){
            e.insert({i + 1 , j + 1});
        }
    }
    if(N % 2 == 0){
        for(int i = 0;i < N / 2;i++){
            e.erase({i + 1, N - i});
        }
    }else{
        for(int i = 0;i < N / 2;i++){
            e.erase({i + 1, N - i - 1});
        }
    }
    cout<<e.size()<<endl;
    for(auto a : e){
        cout<<a.first<<" "<<a.second<<endl;
    }
    return 0;
}