#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> ms(N);
    int counter = 0;
    rep(i, N){
        cin >> ms.at(i);
        X -= ms.at(i);
        counter++;
    }

    sort(ms.begin(), ms.end());
    rep(i, N){
        while(X > 0){
            int consume = ms.at(i);
            if(X >= consume){
                X -= consume;
                counter++;
            } else {
                break;
            }
        }
    }
    cout << counter << endl;
}