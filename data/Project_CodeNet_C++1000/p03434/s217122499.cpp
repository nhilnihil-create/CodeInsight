#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a=0,b=0;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++){
        cin >> data.at(i);
    }
    sort(data.begin(), data.end());//小さい順に並べる
    reverse(data.begin(), data.end());//リバース   
    for (int i = 0; i < n; i++){
        if(n % 2 == 0){
            a += data.at(i);
            i++;
            b += data.at(i);
        }else{
            a += data.at(i);
            i++;
            if(i < n){
                b+= data.at(i);
            }
        }
    }
    cout << a-b << endl;
}