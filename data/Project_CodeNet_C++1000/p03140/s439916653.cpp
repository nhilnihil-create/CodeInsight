#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, cnt=0;
    cin >> N;
    string A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;

    for(int i=0; i<N; i++){
        if(A.at(i)!=B.at(i) && A.at(i)!=C.at(i) && B.at(i)!=C.at(i)) cnt+=2;
        else if(A.at(i)==B.at(i) && A.at(i)==C.at(i)) cnt+=0;
        else if(A.at(i)==B.at(i) || A.at(i)==C.at(i) || B.at(i)==C.at(i)) cnt++;
    }
    cout << cnt << endl;
}
