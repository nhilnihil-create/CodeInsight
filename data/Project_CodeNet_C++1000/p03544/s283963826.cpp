#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int64_t> ryu(N+1);
    ryu.at(0) = 2;
    ryu.at(1) = 1;
    for (int i=2; i<N+1; i++){
        ryu.at(i) = ryu.at(i-1) + ryu.at(i-2);
    }
    cout << ryu.at(N) << endl;

    return 0;

}