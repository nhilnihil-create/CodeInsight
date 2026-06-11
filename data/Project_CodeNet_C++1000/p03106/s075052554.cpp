#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> data(b);
    int j = 0;
    for (int i = 1; i < a+1; i++){
        if(a % i == 0 && b % i == 0){
            data.at(j) = i;
            j++;
        }
    }
    sort(data.begin(), data.end());//小さい順に並べる
    reverse(data.begin(), data.end());//リバース
    cout << data.at(k-1) << endl;
}