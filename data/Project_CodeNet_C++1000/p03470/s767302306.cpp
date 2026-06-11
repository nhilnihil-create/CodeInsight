#include <bits/stdc++.h>
using namespace std;

int main (){
    int N;
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; i++) cin >> d.at(i);
    
    vector<int>num(110);
    for (int i = 0; i < N; i++){
        num.at(d.at(i)) = 1;
    }

    int ans = 0;
    for(int i = 1; i < 101; i++){
        if (num.at(i) == 1) ans++;
    }
    cout << ans << endl;
}