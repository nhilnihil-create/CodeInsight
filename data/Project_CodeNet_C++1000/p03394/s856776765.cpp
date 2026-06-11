#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main() {
int N; 
cin >> N; 
int A[5010] = {}, B[15010] = {}; 
for(int i = 0; i < 5000; i++){
A[i] = (i+1) * 6;
}
for(int i = 0; i < 2500; i++){
B[i * 4] = i * 6 + 2; 
B[i * 4 + 1] = i * 6 + 4; 
B[i * 4 + 2] = i * 12 + 3; 
B[i * 4 + 3] = i * 12 + 9;
}
for(int i = 5000; i < 7500; i++){
B[i * 2] = i * 6 - 14998; 
B[i * 2 + 1] = i * 6 - 14996; 
}

if(N == 3){
cout << 2 << " " << 5 << " " << 63; 
}
else if(N >= 4 && N <= 15000){
for(int i = 0; i < N / 2; i++){
cout << B[i * 2] << " " << B[i * 2 + 1] << " ";   
}
if(N % 2 == 0){
cout << endl; 
}
else if(N % 2 == 1){
cout << A[0] << endl; 
}
}
else if(N >= 15001 && N <= 20000){
for(int i = 0; i < 15000; i++){
cout << B[i] << " ";   
}
for(int i = 0; i < N - 15000; i++){
cout << A[i] << " ";   
}
}
}