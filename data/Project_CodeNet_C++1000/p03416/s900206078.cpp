#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    int res=0;
    string S="", R="";
    for(int i=A; i<=B; i++){
        S = to_string(i);
        R = S;
        reverse(R.begin(), R.end());
        if(S == R)
            res++;
    }
    cout << res << endl;
    return 0;
}