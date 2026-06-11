#include<bits/stdc++.h>
#define ll long long
#define P pair<int ,int>
using namespace std;

struct edge{
    ll to ,cost;
};

ll pow(ll a ,ll n){
    if(n==0) return a;
    else return a*pow(a ,n-1);
}
int main(){
    ll n;
    cin >> n;
    ll m = pow(2 ,n);
    ll k;
    cin >> k;
    if(n==1 && k==0){
        cout << "0 0 1 1" << endl;
        return 0;
    }if((n==1 && k== 1)|| k >= m) {
        cout << "-1" << endl;
        return 0;
    }

    for(int i=0;i<m;i++){
        if(i==k)continue;
        cout << i <<" ";
    }
    cout << k << " ";
    for(int i=m-1;i>=0;i--){
        if(i==k)continue;
        cout << i << " ";
    }
    cout << k <<endl;

}
