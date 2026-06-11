#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define V vector<ll>
using namespace std;
using ll = long long;


int main(){
    int a,b;
    cin>>a>>b;
    int dif=b-a;
    int B=0;
    Rep(i,1,b-a) B+=i;
    cout<<B-b<<endl;
}