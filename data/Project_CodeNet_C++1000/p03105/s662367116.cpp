#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main(){
    int a,b,c;cin>>a>>b>>c;
    int d=b/a;
    if(d>c){
        cout<<c<<endl;
    }
    else{
        cout<<d<<endl;
    }
}