#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    if(abs(a-b)<=d && abs(b-c)<=d){
        cout << "Yes" << endl;
    }else if(abs(a-c)<=d){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}