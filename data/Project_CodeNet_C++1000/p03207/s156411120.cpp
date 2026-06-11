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
    for (int i = 0; i < n; i++){
        if(i == 0){
            sum += data.at(i) / 2;
        }else{
            sum += data.at(i);
        }
    }
    cout << sum << endl;
}