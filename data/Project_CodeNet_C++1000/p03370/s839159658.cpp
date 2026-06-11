#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,X,wa=0;
    cin >> N >> X;
    vector<int> m(N);

    for(int i = 0;i < N;i++){
        cin >> m.at(i);
    }

    for(int i = 0;i < N;i++){
        X -= m.at(i);
        wa++;
    }

    sort(m.begin(),m.end());

    while(X - m.at(0) >= 0){
        X -= m.at(0);
        wa++;
    }

    cout << wa << endl;
}