/**
*    author:  souzai32
*    created: 11.08.2020 20:19:26
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    vector<int> k(m),p(m);
    vector<vector<int>> s(m,vector<int>(n));
    rep(i,m){
        cin >> k.at(i);
        rep(j,k.at(i)){
            cin >> s.at(i).at(j);
        }
    }
    rep(i,m) cin >> p.at(i);

    vector<bool> sw(n);
    int count=0,check,num;
    bool light;
    for(int i=0; i<pow(2,n); i++){
        num=i;
        light=true;
        rep(j,n){
            if(num%2==1) sw.at(j)=true;
            else sw.at(j)=false; 
            num/=2;
        }
        rep(j,m){
            check=p.at(j);
            rep(l,k.at(j)){
                if(sw.at(s.at(j).at(l)-1)) check++;
            }
            if(check%2) light=false;
        }
        if(light) count++;
        /*for(int j=0; j<n; j++){
            cout << sw.at(j) << ' ';
        }   
        cout << endl;
        cout << count << endl;*/
    }
    
    cout << count << endl;

    return 0;
}