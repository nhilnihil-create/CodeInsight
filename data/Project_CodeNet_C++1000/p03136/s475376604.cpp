#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N;
   int x;
   int maxi_king;
   int max_bs;
   vector <int> sanyiszamok;
   cin >> N;
   for(int i=0;i<N;i++){
     cin >> x;
    sanyiszamok.push_back(x);
   }
   maxi_king=0;
   max_bs=sanyiszamok[0];
   for(int i=1;i<N;i++){
     if(sanyiszamok[i]>max_bs){
       max_bs=sanyiszamok[i];
       maxi_king=i;
     }
   }
   int osszegsanyi=0;
   for(int i=0;i<N;i++){
     osszegsanyi+=sanyiszamok[i];
     
   }  
   osszegsanyi-=max_bs;
   if(max_bs<osszegsanyi){
     cout << "Yes";
   }else{
     cout << "No";
   }
	return 0;
}
