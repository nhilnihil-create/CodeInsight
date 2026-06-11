#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    int N;
    cin >> N;
    cout << 0 << endl;
    string S;
    cin >> S;
    string S0 = S;
    if(S == "Vacant") return 0;
    int l=1,r=N;

    while(true){
        int mid = (l+r) / 2;
        cout << mid << endl;
        cin >> S;
        if(S == "Vacant") return 0;
        if(mid % 2 == 0 && S == S0){
            l = mid;
        }else if(mid % 2 == 1 && S != S0){
            l = mid;
        }else{
            r = mid;
        }
    }

    return 0;
}