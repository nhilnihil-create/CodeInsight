#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;

int main(){
    string S; cin >> S;
    int s1=0, s2=0;
    rep(i, S.size()){
        if(i%2==1){
            if(S[i]!='1') s1++;
            else s2++;
        }
        else{
            if(S[i]!='1') s2++;
            else s1++;
        }
    }
    cout << min(s1, s2) << endl;
    return 0;
}
