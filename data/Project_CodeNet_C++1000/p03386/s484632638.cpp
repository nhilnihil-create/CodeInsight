#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int a,b,k;
    cin >> a >> b >> k;
    map<int,int> used;
    rep(i,k){
        if(i+a<=b){
            cout << i+a << endl;
            used[i+a]=1;
        }
        else break;
    }
    rep(i,k){
        if((!used.count(b-k+i+1))&&(b-k+i+1>a))cout << b+i+1-k << endl;
    }
}