#include "bits/stdc++.h"
using namespace std;

int main(){
    int N;
    cin >> N;
    double sum=0;

    for(int i=0;i<N;i++){
        double A;
        string S;
        cin >> A >> S;
        if(S == "BTC") sum+= 380000*A;
        else sum += A;
    }
    cout << sum << endl;

}