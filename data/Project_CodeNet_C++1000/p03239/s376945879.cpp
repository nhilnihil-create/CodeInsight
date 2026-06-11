#include <bits/stdc++.h>
using namespace std;
struct Keiro
{
    int c;
    int t;

    void keiroPB(int ci, int ti){
        c = ci;
        t = ti;
    }
};

int main(){
    int n,t;
    cin>>n>>t;
    vector<Keiro> keiro(n);
    for(int i=0;i<n;i++){
        int ci,ti;
        cin >> ci >> ti;
        keiro[i].keiroPB(ci,ti);
    }
    int minC = 1000000;
    for(int i=0;i<n;i++){
        if(keiro[i].t <= t){
            minC = min(keiro[i].c, minC);
        }
    }
    if(minC == 1000000) cout<<"TLE"<<endl;
    else cout<<minC<<endl;
}