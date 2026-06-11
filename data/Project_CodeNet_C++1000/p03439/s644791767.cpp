#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;

    ll L = 0, R = N;
    string sL, sR, sM;
    cout << 0 << endl;
    cin >> sL;
    if(sL == "Vacant"){
        cout << L << endl;
        return 0;
    }
    sR = sL;
    while(true){
        ll M = (L+R)/2;
        cout << M << endl;
        cin >> sM;
        if(sM == "Vacant"){
            cout << M << endl;
            break;
        }

        if((M-L-1)%2 == 1){
            if(sL == sM){
                //探索に不適
                L = M;
                sL = sM;
            }else{
                //確実に空席あり
                R = M;
                sR = sM;
            }
        }else{
            if(sL == sM){
                //確実に空席あり
                R = M;
                sR = sR;
            }else{
                //探索に不適
                L = M;
                sL = sM;
            }
        }
    }
    return 0;
}