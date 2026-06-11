#include <bits/stdc++.h>
using namespace std;

int solve(int custo,int total,int tempo){

        int tempo2=0,total2=0,i=1;

        while (tempo2<tempo){
                tempo2=i*custo;
                i++;
                if (tempo2<tempo){
                total2+=total;
                }
        }

return total2;



}

int main(){

int a,b,t;
cin >> a >> b >> t;
a=a*10;
t=t*10+5;


cout << solve(a,b,t)<<endl;


return 0;
}
