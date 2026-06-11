#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int main(){
    int a,b,c,x;
    cin >> a >> b >> c >> x;
    int cnt=0;
    for(int i=a;i>=0;i--){
        for(int j=b;j>=0;j--){
            for(int k=c;k>=0;k--){
                if(500*i+100*j+50*k==x) ++cnt;
            }
        }
    }
    cout << cnt << endl;
}