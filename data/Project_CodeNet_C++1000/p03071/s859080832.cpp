#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
int Ans = 0;
int A, B;cin >> A >> B;
int a = A, b = B;

for(int i = 0; i <= 2; i++){
int P = 0;
for(int j = 0; j < i; j++){
P += A;A -= 1;}

for(int k = 0; k < 2 - i; k++){
P += B;B -= 1;}

Ans = max(Ans, P);
A = a;B =b;
}

cout << Ans << endl;

}