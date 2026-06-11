#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main(){
    vector<int> v(6);
    rep(i,6) cin >> v.at(i);

    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 5; j++){
            if(v.at(j) - v.at(i) > v.at(5)){
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
}