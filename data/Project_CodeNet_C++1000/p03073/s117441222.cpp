#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
string S;cin >> S;
string T = S;
int Ans = 0;
int A = 0, B = 0;

for(int i = 0; i < S.length(); i++){

if(i%2 == 0 && S.at(i) == '1'){
S.at(i) = '0';A++;}

if(i%2 == 1 && S.at(i) == '0'){
S.at(i) = '1';A++;}

}

S = T;

for(int i = 0; i < S.length(); i++){

if(i%2 == 0 && S.at(i) == '0'){
S.at(i) = '1';B++;}

if(i%2 == 1 && S.at(i) == '1'){
S.at(i) = '0';B++;}

}
Ans = min(A, B);cout << Ans << endl;
}