#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repp(i,a,b)  for(int i=a;i<=(int)(b);i++)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int main(){
    cs;
    int x;
    vector<int> v(5);
    rep(i,5) cin>>v[i];
    cin>>x;
    rep(i,5){
        repp(j,i+1,4) if(v[j]-v[i]>x) {cout<<":(";return 0;}
    }
    cout<<"Yay!";
}