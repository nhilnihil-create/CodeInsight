#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int a,b;
    cin >> a >> b;

    if(a==b){
        cout << "Yay!" << endl;
    }else if(max(a,b)*2<=16){
        cout << "Yay!" << endl;
    }else{
        cout << ":(" << endl;
    }

    return 0;
}