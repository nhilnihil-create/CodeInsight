#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string A,B;
    cin >> A >> B;
    if(A[0] == B[0]){
        cout << "=" << endl;
        return 0;
    }
    if(A[0] > B[0]){
        cout << ">"  << endl;
    }else{
        cout << "<" << endl;
    }
    return 0;
}