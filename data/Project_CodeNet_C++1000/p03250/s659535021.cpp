#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> data(3);
    cin >> data.at(0) >> data.at(1) >>data.at(2);
    sort(data.begin(), data.end());//小さい順に並べる
    reverse(data.begin(), data.end());//リバース
    cout << data.at(0)*10+data.at(1)+data.at(2) << endl;
}