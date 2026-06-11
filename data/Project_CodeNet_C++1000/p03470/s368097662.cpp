#include <bits/stdc++.h>
using namespace std;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N;
    cin >> N;

    vector<int> d(N);
    rep2(i, 0, N) cin >> d.at(i);

    int temp;
    rep2(i, 0, N){
        rep2(j, 0, N-1-i){
            if(d.at(j) < d.at(j+1)){
                temp = d.at(j);
                d.at(j) = d.at(j+1);
                d.at(j+1) = temp;
            }
        }
    }

    int X = 1;
    rep2(i, 1, N){
        if(d.at(i-1) != d.at(i)) X++;
    }

    cout << X << endl;
}
