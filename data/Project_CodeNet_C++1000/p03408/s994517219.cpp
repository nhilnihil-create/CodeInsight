#include <bits/stdc++.h>
#include <math.h>
#define ALL(a) a.begin(), a.rbegin()
using namespace std;
int main(){
int N, M;cin >> N;
map<string, int> P;

for(int i = 0; i < N; i++){
string S;
cin >> S;
P[S]++;
}

cin >> M;

for(int i = 0; i < M; i++){
string S;
cin >> S;
P[S]--;
}
int Ans = 0;
for(auto i = P.begin(); i != P.end(); i++){
if(Ans < i->second) Ans = i->second;
}
 cout << Ans << endl;
}