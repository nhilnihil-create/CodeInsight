#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(){
    int a,b;
    cin >> a >> b;
    int sa=b-a;
    int ans=b-a;
    while(sa>0){
        sa--;
        ans+=sa;
    }
    cout << ans-b << endl;
    return 0;
}