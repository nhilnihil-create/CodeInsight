#include <bits/stdc++.h>
using namespace std;

int solve(int custo,int saldo,int vezes){
        int total;
        total=saldo/custo;
        if (vezes<=total){return vezes;}
        else{return total;}
}

int main(){
int a,b,c;

cin >> a >> b >> c;

cout << solve(a,b,c)<<endl;


return 0;
}
