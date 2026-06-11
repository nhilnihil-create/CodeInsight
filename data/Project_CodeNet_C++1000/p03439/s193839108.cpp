#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    ll N;
    string s;
    cin >> N;
    cout << 0 <<endl<<flush;
    cin >> s;
    ll sts;
    if(s == "Vacant"){
        return 0;
    }else if(s == "Male"){
        sts = 0;
    }else{
        sts = 1;
    }
    //ll pre = 0;
    ll L = -1;
    ll R = N;
    while(L  < R -1){
        ll x = (L+R)/2;
        cout << x << endl <<flush;
        cin >> s;
        if(s == "Vacant"){
            return 0;
        }else if(s == "Male"){
            if((x)%2 == 0 && !sts){
                L = x;
                //cout << "a";
            }else if((x)%2 == 1 && sts){
                L = x;
                //cout << "b";
            }else{
                R = x;
                //cout << "c";
            }       
        }else{
            if((x)%2 == 0 && sts){
                L = x;
            }else if((x)%2 == 1 && !sts){
                L = x;
            }else{
                R = x;
            }
        }

    }
}
