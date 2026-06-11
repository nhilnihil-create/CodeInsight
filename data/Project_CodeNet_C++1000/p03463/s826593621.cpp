// AGC 020
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n,a,b; cin >> n >> a >> b;
    int i = 0;
    while(1){
        if(i%2 == 0){
            if(a+1 != b){
                a++;
            }else{
                if(a-1 <= 0) break;
                else a--;
            }
        }else{
            if(b-1 != a){
                b--;
            }else{
                if(b+1 > n) break;
                else b++;
            }
        }
        i++;
    }

    if(i%2 == 0) cout << "Borys" << endl;
    else cout << "Alice" << endl;
    return 0;
}