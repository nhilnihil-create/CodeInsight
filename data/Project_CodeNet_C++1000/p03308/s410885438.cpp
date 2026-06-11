#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N;
    vector<int> A;
    cin >> N;
    for (int i = 0; i < N; ++i){
        int a;
        cin >> a;
        A.push_back(a);
    }
    int M = A[0];
    int m = A[0];
    for (int i = 0; i < N; ++i)
    {
        if(A[i] > M){
            M = A[i];
        }
        if(A[i] < m){
            m = A[i];
        }
    }
    cout << M - m << endl;
}