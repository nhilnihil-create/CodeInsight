#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    long n;
    cin >> n;
    vector<tuple<long,long,long>> c;
    rep(i,n){
        long a,b;
        cin >> a >> b;
        c.push_back(make_tuple(a+b,a,b));
    } 
    sort(c.begin(),c.end());
  	reverse(c.begin(),c.end());
    long t =0,a=0,flag = 1;
    for(auto i:c){
        long x,y,z;
        tie(x,y,z) = i;
        if(flag%2) t += y; 
        else a += z;
        flag++;
    }
    cout << t-a << endl;
}
