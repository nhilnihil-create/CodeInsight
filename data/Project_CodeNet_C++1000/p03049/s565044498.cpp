#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N;
    cin >> N;
    string tmp;
    int cnt = 0;
    int acnt = 0;
    int bcnt = 0; 
    int check = 1;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        if(tmp.at(0) == 'B') bcnt++;
        if(tmp.at(tmp.size() - 1) == 'A') acnt++;
        if((tmp.at(0) == 'B') || (tmp.at(tmp.size() - 1) == 'A') ) {
            if( !(tmp.at(0) == 'B') || !(tmp.at(tmp.size() - 1) == 'A') ){
                check = 0;
            }
        }
        for (int j = 0; j < tmp.size() - 1 ; j++)
        {
            if(tmp.at(j) == 'A' && tmp.at(j+1) == 'B'){
                cnt++;
            }
        }
    }
    if(acnt == 0 || bcnt == 0) check = 0;
    printf("%d\n", cnt + min(acnt,bcnt) - check);

    
}
