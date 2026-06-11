#include <bits/stdc++.h>
using namespace std;
double Y(int T,int H){
    
    return T - 0.006 * H;
}

int main(void){
   
   int N,T,A,H,ans=1;
   double min;
   cin >> N >> T >> A;
   for(int i=1;i<=N;i++){
       cin >> H;
       if(i==1) min = abs(A-Y(T,H));
       else{
            double r = abs(A-Y(T,H));
            if(min > r){
                min = r;
                ans = i;
            }
       }
   }
   cout << ans << endl;
}