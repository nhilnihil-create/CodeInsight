#include <bits/stdc++.h>
using namespace std;

int main() {
long long N, K;
cin >> N >> K;
vector<int> Array(N);
vector<int> count(N);
for(int i = 0; i < N; i++){
cin >> Array.at(i);}
for(int i = 0; i < N; i++){
count.at((Array.at(i) - 1))++;}
sort(count.begin(), count.end());
int sum = 0;
for(int i = 0; i < N - K; i++){
sum += count.at(i);}
cout << sum << endl;}
