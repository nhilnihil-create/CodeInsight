#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
    int N, A, B;
    cin >> N >> A >> B;
    int cn1 = 0, cn2 = 0, cn3 = 0;
    rep(i,N){
        int p;
        cin >> p;
        if(p<=A) cn1++;
        else if(p <= B) cn2++;
        else cn3++;
    }

    cout << min(cn1, min(cn2,cn3)) << endl;
}   