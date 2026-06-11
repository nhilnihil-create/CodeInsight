#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<long long int> num(5,0);
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        if(s.at(0)=='M') num.at(0)++;
        if(s.at(0)=='A') num.at(1)++;
        if(s.at(0)=='R') num.at(2)++;
        if(s.at(0)=='C') num.at(3)++;
        if(s.at(0)=='H') num.at(4)++;
    }

    long long int ans=0;
    for(int i=0; i<3; i++){
        for(int j=i+1; j<4; j++){
            for(int k=j+1; k<5; k++){
                ans+=num.at(i)*num.at(j)*num.at(k);
                //cout << num.at(i) << ' ' << num.at(j) << ' ' << num.at(k) << endl;
            }
        }
    }

    cout << ans << endl;
}