#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

ll k,a,b;

int main(){
    cin >> k >> a >> b;
    ll res=1;
    if(a+2>=b){
        res+=k;
    }
    else if(a+2<b){
        if(k<=a-1){
            res+=k;
        }
        else if(k>a-1&&(k-a+1)%2==1){
            res+=a-1;
            res+=(b-a)*((k-a+1)/2);
            res+=1;
        }
        else if(k>a-1&&(k-a+1)%2==0){
            res+=a-1;
            res+=(b-a)*((k-a+1)/2);
        }
    }
    cout << res << endl;
}  