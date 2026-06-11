#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long A, B, C, K;
    cin >> A >> B >> C >> K;
    
    if(abs(A-B) > round(pow(10,18))){
        cout << "Unfair" << endl;
        return 0;
    }

    if(K%2 == 0){
        cout << A-B << endl;
    }else{
        cout << B-A << endl;
    }
    return 0;

}