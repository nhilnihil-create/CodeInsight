#include <bits/stdc++.h>
using namespace std;

int main() {
 int N;
 cin >> N;

 vector<int64_t>S(N);

 for(int i = 0; i < N; i++){
     cin >> S.at(i);
     }

 int sum = 0;

 bool M = true;
 while(M){

    for(int j = 0; j < N; j++){
         if(S.at (j) % 2 != 0){
             M = false;
             break;
             }
         if(S.at(j) % 2 == 0){
             S.at(j) = S.at(j) / 2;
             }

    }
    
    sum++;
 }

 cout << sum -1 << endl;

}