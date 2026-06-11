#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,X;
    cin >> A >> B >> X;

    if(A > X){
        cout << "NO";
    }else{
        X-A<=B?cout<<"YES":cout<<"NO";
    }
    return 0;
}