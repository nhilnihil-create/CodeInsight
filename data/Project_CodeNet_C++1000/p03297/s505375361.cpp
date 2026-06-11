#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100000 + 10;
int main(){
    int T; cin>>T;
    while(T--){
        ll A,B,C,D; cin>>A>>B>>C>>D;
        if(A<B) cout<<"No"<<endl;
        else if(D<B) cout<<"No"<<endl;
        else{
            if(C>=B-1) cout<<"Yes"<<endl;
            else{
                D %= B;
                if(D==0){
                    A %= B;
                    if(A<=C) cout<<"Yes"<<endl;
                    else cout<<"No"<<endl;
                }
                else{
                    ll d = __gcd(D,B);
                    if(B-(d-A%d)<=C) cout<<"Yes"<<endl;
                    else cout<<"No"<<endl;
                }
            }
        }
    }
}
