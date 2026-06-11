#include <bits/stdc++.h>
using namespace std;

int N,R,price=0,C,M;
bool y=false;

int main(){
    cin >> N;
    for(int i=1;i<=N;i=i+2){
        for(int i=2;i<=N;i=i+2){
            price++;
        }
    }
    cout << price << endl;
}