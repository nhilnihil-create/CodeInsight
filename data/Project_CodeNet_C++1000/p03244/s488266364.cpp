#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    vector<int> even(100005,0), odd(100005,0);
    int tmp,n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        if(i % 2 == 1){
            odd.at(tmp)++;
        }
        else{
            even.at(tmp)++;
        }
    }

    int maxeven,secondeven,eveni,maxodd,secondodd,oddi;
    maxeven = 0; secondeven = 0; maxodd = 0; secondodd = 0;
    eveni = 0; oddi = 0;

    for(int i = 0; i < 100005; i++){
        if(even.at(i) > maxeven){
            secondeven = maxeven;
            maxeven = even.at(i);
            eveni = i;
        }
        else if(even.at(i) > secondeven){
            secondeven = even.at(i);
        }
        if(odd.at(i) > maxodd){
            secondodd = maxodd;
            maxodd = odd.at(i);
            oddi = i;
        }
        else if(odd.at(i) > secondodd){
            secondodd = odd.at(i);
        }
    }
    if(eveni != oddi){
        printf("%d\n", n - maxeven - maxodd);
    }
    else{
        printf("%d\n", min(n - maxeven - secondodd, n - secondeven - maxodd));
    }

}
