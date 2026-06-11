#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int main(){
    int a,b,k;
    cin >> a >> b >> k;
    for(int i=a;i<=b;i++){
        if(i<a+k) cout << i << endl;
        else if(i>b-k) cout << i << endl;
    }
}