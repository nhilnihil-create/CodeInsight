#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N, T, A;
    cin >> N;
    cin >> T >> A;
    vector<int> h(N + 1);
    int min = 10000000000;
    int res;
    for(int i = 1; i <= N; i++){
        cin >> h.at(i);
        int d = abs((T * 1000 - h.at(i) * 6) - A * 1000);
        if(d < min){
            min = d;
            res = i;
        }
    }
    cout << res << endl;
}