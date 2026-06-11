/**
*    author:  souzai32
*    created: 14.08.2020 12:05:39
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> c(n-1),s(n-1),f(n-1);
    rep(i,n-1) cin >> c.at(i) >> s.at(i) >> f.at(i);

    vector<int> time(n);

    for(int i=0; i<n-1; i++){
        time.at(i)+=s.at(i)+c.at(i);
        for(int j=i+1; j<n-1; j++){
            if(time.at(i)<=s.at(j)) time.at(i)=s.at(j);
            else if((time.at(i)-s.at(j))%f.at(j)) time.at(i)+=f.at(j)-(time.at(i)-s.at(j))%f.at(j);
            time.at(i)+=c.at(j);
        }
    }
    
    rep(i,n) cout << time.at(i) << endl;

    return 0;
}