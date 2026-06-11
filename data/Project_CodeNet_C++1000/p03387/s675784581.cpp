#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int A, B, C;
    int x = 0;
    cin >> A >> B >> C;
    if(A%2 == B%2 && C%2 != B%2) {
        A++;
        B++;
        x++;
    }
    else if(A%2 == C%2 && B%2 != C%2) {
        A++;
        C++;
        x++;
    }
    else if(A%2 != B%2 && B%2 == C%2) {
        B++;
        C++;
        x++;
    }
    
    if(A <= B && B <= C){
        x += (C-A)/2;
        x += (C-B)/2;
    }
    else if(A <= C && C <= B){
        x += (B-A)/2;
        x += (B-C)/2;
    }
    else if(B <= A && A <= C){
        x += (C-A)/2;
        x += (C-B)/2;
    }
    else if(B <= C && C <= A){
        x += (A-C)/2;
        x += (A-B)/2;
    }
    else if(C <= A && A <= B){
        x += (B-C)/2;
        x += (B-A)/2;
    }
    else if(C <= B && B <= A){
        x += (A-C)/2;
        x += (A-B)/2;
    }
    cout << x << endl;
    return 0;
}