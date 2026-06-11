#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin >> n;
    int A[n];
    int B[n];
    int C[n];

    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        A[i] = a;
        B[i] = b;
        C[i] = c;
    }
    int a_happiness[n];
    int b_happiness[n];
    int c_happiness[n];
    a_happiness[0] = A[0];
    b_happiness[0] = B[0];
    c_happiness[0] = C[0];

    for(int i=1;i<n;i++){
        a_happiness[i] = max(b_happiness[i-1],c_happiness[i-1]) + A[i];
        b_happiness[i] = max(c_happiness[i-1],a_happiness[i-1]) + B[i];
        c_happiness[i] = max(a_happiness[i-1],b_happiness[i-1]) + C[i];
    }

    int maxi = max(a_happiness[n-1],b_happiness[n-1]);
    maxi = max(maxi,c_happiness[n-1]);

    cout << maxi << endl;

    return 0;
}
