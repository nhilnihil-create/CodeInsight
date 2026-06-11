#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
using Lf = long double;
using plong = pair<ll,ll>;
const int MOD = 1000000007;
bool field[100][100];
int main(){
    ll A,B;cin>>A>>B;
    for(ll i=0;i<100;i++){
        for(ll j=0;j<100;j++){
            if(i<50)field[i][j] = true;
            else field[i][j] = false;
        }
    }
    ll x=0,y=0,a=0;
    while(a<A-1){
        field[x][y] = false;
        a++;
        y+=2;
        if(y>=100){
            x+=2;
            y=1;
        }
    }
    x=51;y=0;
    ll b=0;
    while(b<B-1){
        field[x][y] = true;
        b++;
        y+=2;
        if(y>=100){
            x+=2;
            y=1;
        }
    }
    cout<<100<<" "<<100<<endl;
    for(ll i=0;i<100;i++){
        for(ll j=0;j<100;j++){
            cout<<(field[i][j]?"#":".");
        }
        cout<<"\n";
    }


}