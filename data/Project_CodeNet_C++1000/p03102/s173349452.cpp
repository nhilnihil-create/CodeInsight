#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,M,C;
    cin >> N >> M >> C;
    vector<int> vecB(M);
    for(int i=0;i<M;i++){
        cin >> vecB.at(i);
    }
   vector<vector<int>> vecA(N,vector<int>(M));
   for(int i=0;i<N;i++){
       for(int j=0;j<M;j++){
           cin >>vecA.at(i).at(j);
       }
   }
   int count = 0;
   for(int i=0;i<N;i++){
       int XX =0;
       for(int j=0;j<M;j++){
           XX += vecB.at(j)*vecA.at(i).at(j);
       }
       XX += C;
       if(XX>0){
           ++ count;
       }
   }
   cout << count << endl;
}