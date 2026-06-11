#include<bits/stdc++.h>
using namespace std;
vector<bool> IsPrime;
void eratosthenes(int max){
    if(max+1 > IsPrime.size()){
        IsPrime.resize(max+1,true);
    }
    IsPrime[0] = false;
    IsPrime[1] = false;
    for(int i = 2;i*i<=max;i++){
        if(IsPrime[i]){
            for(int j = 2;i*j<=max;j++){
                IsPrime[i*j] = false;
            }
        }
    }
}
int Tto1(bool b){
    return b?1:0;
}
bool isgood(int a){
    if(IsPrime[a] && IsPrime[(a+1)/2]){
        return true;
    } 
    return false;
}
int main(){
    int Q;
    cin >> Q;
    struct lr{
        int l;
        int r;
    };
    vector<lr> qlist(Q,lr{0,0});
    for(int i = 0;i<Q;i++){
        cin >> qlist[i].l >> qlist[i].r;
    }
    eratosthenes(100001);
    array<int,100001> ruiseki{0};
    for(int i = 1;i<100001;i++){
        ruiseki[i] = ruiseki[i-1] + Tto1(isgood(i));
    }
    for(int i = 0;i<Q;i++){
        cout << ruiseki[qlist[i].r] - ruiseki[qlist[i].l-1] << endl;
    }
    return 0;
}