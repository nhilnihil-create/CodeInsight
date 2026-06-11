#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, m;
    int cnt = 0;

    cin >> num >> m;

    if(num >= m){
        cout << 0;
        return 0;
    }

    vector<int> vec(m);
    vector<int> tmp(m-1);

    for(int i = 0; i < m; i++) cin >> vec.at(i);
    sort(vec.begin(), vec.end(), greater<int>());

    for(int i =0; i < m-1; i++){
        tmp.at(i) = abs(vec.at(i) - vec.at(i+1));
    }


    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < tmp.size() - num + 1; i++){
        cnt += tmp.at(i);
    }

    cout << cnt;
}