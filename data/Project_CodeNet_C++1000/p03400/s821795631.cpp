#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1000000000; //10^9

int main(){
    int N;
    cin >> N; // numbar of human
    int D, X; // D: days , X:number of chocolate
    cin >> D >> X;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    for(int i = 0; i < N; i++){
        int j = 0;
        int day = 1;
        while (day <= D){
            day = 0;
            X++;
            j++;
            day += j * A.at(i) + 1;
        }
    }
    cout << X << endl;
}
