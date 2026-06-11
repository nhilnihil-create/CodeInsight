#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int A = N / 1000, B = N / 100 % 10, C = N / 10 % 10, D = N % 10;

    if(A+B+C+D == 7) cout<<A<<'+'<<B<<'+'<<C<<'+'<<D<<"=7";
    else if(A+B+C-D == 7) cout<<A<<'+'<<B<<'+'<<C<<'-'<<D<<"=7";
    else if(A+B-C+D == 7) cout<<A<<'+'<<B<<'-'<<C<<'+'<<D<<"=7";
    else if(A-B+C+D == 7) cout<<A<<'-'<<B<<'+'<<C<<'+'<<D<<"=7";
    else if(A-B-C+D == 7) cout<<A<<'-'<<B<<'-'<<C<<'+'<<D<<"=7";
    else if(A+B-C-D == 7) cout<<A<<'+'<<B<<'-'<<C<<'-'<<D<<"=7";
    else if(A-B+C-D == 7) cout<<A<<'-'<<B<<'+'<<C<<'-'<<D<<"=7";
    else if(A-B-C-D == 7) cout<<A<<'-'<<B<<'-'<<C<<'-'<<D<<"=7";




}