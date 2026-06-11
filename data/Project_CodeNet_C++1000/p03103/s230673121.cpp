#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef struct _store{
    int value;
    int num;
}Store;

bool comp(const Store& lh, const Store& rh) {
     
     return lh.value < rh.value;
}

int main(){

   int N,M; cin >> N >> M;
   ull ans = 0;
   Store S[N];
   
   for(int i=0;i<N;i++){
       cin >> S[i].value;
       cin >> S[i].num;
   }
   
   sort(S,S+N,comp);
   
   for(int i=0;i<N;i++){
       if(S[i].num < M){
           M -= S[i].num;
           ans += ((ull)S[i].num*S[i].value);
       }
       else{
           ans += ((ull)M * S[i].value);
           break;
       }
   }
   
   cout << ans << endl;
}