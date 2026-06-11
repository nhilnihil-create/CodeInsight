#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
int N, M;
cin >> N >> M;
int food[100][100];

for(int i = 0; i < N; i++){
for(int j = 0; j < M; j++){
food[i][j] = 0;
}
}

for(int i = 0; i < N; i++){
    int K;
cin >> K;
for(int j = 0; j < K; j++){
int tabe;
cin >> tabe;
tabe--;
food[i][tabe] = 1;
}
}
int count = 0;
for(int i = 0; i < M; i++){
    bool check = 1;
for(int j = 0; j < N; j++){
if(food[j][i] != 1) check = 0;
}
if(check == 1)count++;
}


cout << count << endl;

}