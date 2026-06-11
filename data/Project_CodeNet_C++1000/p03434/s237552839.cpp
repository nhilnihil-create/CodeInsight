#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int A[200];
    for (int i = 0;i < n;i++) cin >> A[i];
    sort(A, A + n, greater<int>());
    int Alice = 0,Bob = 0;
    for (int i = 0;i < n;i++){
        if (i % 2 == 0) Alice += A[i];
        else Bob += A[i];
    }
    cout << Alice - Bob << endl;
    return 0;
}