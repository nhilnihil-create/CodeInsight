#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
int main() {
    string s;
    int n,i1,count;
    i1=0;
    count=0;
    cin >> s;
    n=s.size();
    rep(i,n){
        if(s.at(i)=='A' || s.at(i)=='T'|| s.at(i)=='C'|| s.at(i)=='G'){
            i1=i1+1;
            count=max(count,i1);
        }
        else{
            i1=0;
        }
    }
    cout << count;
}