#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int>d = {};
    int i;
    for(i = 0;i < n;i++){
        int m;
        cin >> m;
        int j;
        for(j = 0;j < d.size();j++){
            if(m == d.at(j)){
                break;
            }
        }
        if(j == d.size()){
            d.push_back(m);
        }
    }
    cout << d.size() << endl;
}