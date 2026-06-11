#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    vector<int> a(5);
    rep(i,5){
        cin >> a.at(i);
    }
    sort(a.begin(),a.end());
    int k;
    cin >> k;
    int p = a.at(4)-a.at(0);
    if(k>=p){
        cout <<"Yay!"<<endl;
    }
    else{
        cout <<":("<<endl;
    }
}