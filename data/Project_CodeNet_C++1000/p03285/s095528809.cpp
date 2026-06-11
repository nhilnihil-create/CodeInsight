#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
int main(){
    int n;cin>>n;
    bool ok=false;
    for(int a=0;a<25;a++){
        for(int b=0;b<15;b++){
            if(4*a+7*b==n)ok=true;
        }
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}