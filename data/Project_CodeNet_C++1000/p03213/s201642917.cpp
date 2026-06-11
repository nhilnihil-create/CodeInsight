#include <bits/stdc++.h>

using namespace std;

map<int,int> res;

void prime_factor(int n){
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            ++res[i];
            n/=i;
        }
    }

    if(n!=1){
        res[n]++;
    }
}

int main(){
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        prime_factor(i);
    }

    int over2=0,over4=0,over14=0,over24=0,over74=0;

    for(int i=2;i<=N;i++){
        if(74<=res[i]){
            over2++;
            over4++;
            over14++;
            over24++;
            over74++;
        }else if(24<=res[i]){
            over2++;
            over4++;
            over14++;
            over24++;
        }else if(14<=res[i]){
            over2++;
            over4++;
            over14++;
        }else if(4<=res[i]){
            over2++;
            over4++;
        }else if(2<=res[i]){
            over2++;
        }
    }

    cout << over74 + over14*(over4-1) + over24*(over2-1) + over4*(over4-1)*(over2-2)/2 << endl;
}