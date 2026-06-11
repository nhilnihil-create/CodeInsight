#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(){

int A,B,K;
cin >> A >> B >> K;

vector<int> ans_1(K);
vector<int> ans_2(K);
int size = 0;

for (int i = 0; i < K; i++){
     if(A + i > B){
          break;
     }
     ans_1.at(i) = A + i;
     size++;
}

for (int i = 1; i <= K; i++){
     ans_2.at(i - 1) = B - K + i;
}

for (int i = 0; i < K; i++){
     if(ans_1.at(i) == 0){
          break;
     }
     cout << ans_1.at(i) << endl;
}

for (int i = 0; i < K; i++){
     if(ans_1.at(size - 1) < ans_2.at(i)){
          cout << ans_2.at(i) << endl;
     }
}



return 0;
}