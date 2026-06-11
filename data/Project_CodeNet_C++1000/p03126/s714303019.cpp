#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,M;
    cin >> N >>M;
    vector<int>vec(N);
   vector<int>vec2(M,0);
   for(int i=0;i<N;i++){
       int K;
       cin >>K;
       vector<int>vec3(K);
       for(int j=0;j<K;j++){
           cin >>vec3.at(j);
           vec2.at(vec3.at(j)-1)++;
       }
   }
   int count =0;
   for(int i=0;i<M;i++){
       if(vec2.at(i)==N){
           count++;
       }
   }
   cout << count <<endl;
}