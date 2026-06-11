#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    int n,m,k,tmp;
    cin >> n >> m;
    vector<int> vec(m);
    rep(i,n){
        cin >> k;
        rep(j,k){
            cin >> tmp;
            vec.at(tmp-1)++;
        }
    }
    tmp=0;
    rep(i,m)if(vec.at(i)==n)tmp++;
    cout << tmp << endl;
}