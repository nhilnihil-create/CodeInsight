#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,sum = 0;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++){
        cin >> data.at(i);
    }
    sort(data.begin(), data.end());//小さい順に並べる
    reverse(data.begin(), data.end());//リバース
    bool flag = 1;
    for (int i = 0; i < n-1; i++){
        sum += data.at(i+1);
    }
    if(sum <= data.at(0))flag = 0;

    if(flag)cout << "Yes" << endl;
    else cout << "No" << endl;
}