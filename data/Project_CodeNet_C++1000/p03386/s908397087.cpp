#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int main(){
    int a,b,k;
    cin >> a >> b >> k;
    int num=a;
    for(num;num<=min(b,(a+k-1));num++) cout << num << endl;
    num=max(num,b-k+1);
    for(num;num<=b;num++) cout << num << endl;
}