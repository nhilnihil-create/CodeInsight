#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i=0; i<N; i++) cin >> a.at(i);

    bool flg = true;
    long long cnt = 0;

    for (int i=0; i<N; i++){
        while(a.at(i)%2 == 0){
            a.at(i) /= 2;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}