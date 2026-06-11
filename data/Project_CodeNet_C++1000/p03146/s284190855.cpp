#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    int s;
    cin >> s;
    vector<int> A;
    A.push_back(s);
    int m;
    while(true){
        int n = A[A.size()-1];
        if(n % 2 == 0) A.push_back(n / 2);
        else A.push_back(3 * n + 1);
        int N = A.size();
        for(int i = 0; i < N - 1; i++){
            if(A[i] == A[N - 1]){
                m = N;
                goto finish;
            }
        }
    }
    finish:
    cout << m << endl;
}
