#include <bits/stdc++.h>
using namespace std;
bool isP(int n){
if(n>2&&n%2==0){ return false; }
for(int i=3; i*i<=n; i+=2){ if(n%i==0){ return false; } }
return true;  
}

int main(){
int N, i; cin >> N; vector<int> P;
for(i=11; i<55555; i+=5){ if(isP(i)){ P.push_back(i); } }
for(i=0; i<N; i++){ cout << P[i] << " "; }
cout << "\n";
}