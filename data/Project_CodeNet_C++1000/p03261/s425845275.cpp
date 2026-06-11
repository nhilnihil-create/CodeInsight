#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
int N;
cin >> N;
string tori[200];
for(int i = 0; i < N; i++){
cin >> tori[i];
}
bool check = 1;
for(int i = 0; i < N; i++){
    int count = 0;
for(int j = 0; j < N; j++){
if(tori[i] == tori[j])count++;
}
if(count > 1)check = 0;
}
for(int i = 0; i < N-1; i++){
int n = tori[i].size();
if(tori[i][n-1] != tori[i+1][0]) check = 0;
}
if(check == 1)cout << "Yes" << endl;
else cout << "No" << endl;

}