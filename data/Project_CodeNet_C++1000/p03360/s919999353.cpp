#include <bits/stdc++.h>
using namespace std;
int main(){
int A, B, C, K, M; cin >> A >> B >> C >> K;
if(A>=B&&A>=C){ A=A<<K; }else if(B>=A&&B>=C){ B=B<<K; }else{ C=C<<K; }
cout << A+B+C << "\n";
}