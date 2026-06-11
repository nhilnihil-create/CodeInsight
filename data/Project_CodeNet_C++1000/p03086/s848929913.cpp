#include<bits/stdc++.h>
#include<algorithm>
#define rep(i, n) for(int i=; i<(n); i++)
using ll = long long;
using namespace std;

int main(){
    string s;
    cin >> s;

    int res = 0;
    int dispose=0;
    for(int i=0; i<s.length(); i++){
        if((s.at(i) == 'A' || s.at(i)=='C') || (s.at(i)=='G' || s.at(i)=='T')){
            dispose++;
            res = max(res, dispose);
        }
            
        else{
            dispose = 0;
        }   
    }
    cout << res << endl;
    return 0;

}