#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    //N += 1;
    vector<int> p(N+1);//Nに到達するまでの最小引き出し数
    p.at(0) = 0;
    vector<int> K(2);
    K.at(0) = 6;
    K.at(1) = 9;
    for(int i = 1; i <= N; i++){
        //cout << i;
        p.at(i)  = p.at(i-1) + 1;
        for(int j =0 ;j<2;j++){
            int amount = K.at(j);
            while(i >= amount ){
                if(p.at(i) > p.at(i-amount)+ 1) p.at(i)  = p.at(i-amount) + 1;
                amount = amount*K.at(j);
            }
        }
            
    }
    cout << p.at(N);
}
