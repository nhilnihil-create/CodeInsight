#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
   string s;
   cin >> s;
    int n=s.size();
    int cnt=0;
    rep(i,n){
        if(s.at(i)=='x')cnt++;
    }
    if(cnt>7)cout << "NO" << endl;
    else cout << "YES" << endl;
}