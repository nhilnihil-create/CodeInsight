/**
*    author:  souzai32
*    created: 14.08.2020 17:21:25
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n,h;
    cin >> n >> h;
    vector<tuple<int,char>> atc(2*n);
    int a,b;
    rep(i,n){
        cin >> a >> b;
        atc.at(2*i)=make_tuple(a,'a');
        atc.at(2*i+1)=make_tuple(b,'b');
    }
    sort(atc.begin(),atc.end(),greater<>());

    int num=0;
    int count=0;
    while(h>0){
        if(get<1>(atc.at(num))=='b'){
            h-=get<0>(atc.at(num));
            num++;
            count++;
        }
        else{
            count+=(h-1+get<0>(atc.at(num)))/get<0>(atc.at(num));
            h=0;
        }
    }
    cout << count << endl;
    return 0;
}