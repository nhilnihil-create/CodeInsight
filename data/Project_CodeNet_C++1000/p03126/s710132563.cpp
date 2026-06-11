#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int k;
    int a;
    vector<int> food(m,0);
    for(int i=0; i<n; i++){
        cin >> k;
        for(int j=0; j<k; j++){
            cin >> a;
            food.at(a-1)++;
        }
    }
    int count=0;
    for(int i=0; i<m; i++){
        if(food.at(i)==n) count++;
//        cout << food.at(i) << endl;
    }
    cout << count << endl;
}