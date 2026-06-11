#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int N, D, X;
    cin >> N >> D >> X;
    vector<int> vec(N);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }

    int choco = X;
    for(int i=0; i<N; i++){
        int d = 1;
        while(d<=D){
            choco++;
            d += vec[i];
        }
    }

    cout << choco << endl;
}