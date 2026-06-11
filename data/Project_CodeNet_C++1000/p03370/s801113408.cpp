#include <bits/stdc++.h>
using namespace std;

int main() {
int N,X;
cin >> N >> X;
vector<int> Dornuts(N);
for(int i = 0; i < N; i++){
cin >> Dornuts.at(i);}
sort(Dornuts.begin(), Dornuts.end());
int sum = 0;
for(int i = 0; i < N; i++){
sum += Dornuts.at(i);}
X -= sum;
int count = 0;
while(X  - Dornuts.at(0) >= 0){
X -= Dornuts.at(0);
count++;}
cout << count + N << endl;
}
