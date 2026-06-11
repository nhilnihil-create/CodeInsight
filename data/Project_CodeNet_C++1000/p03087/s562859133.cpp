#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> AC(N,0);
    string str;
    cin >> str;
    for(int i = 0; i < N - 1; i++){
        if(str[i] == 'A' && str[i + 1] == 'C'){
            AC[i + 1] = AC[i] + 1;
        }
        else{
            AC[i + 1] = AC[i];
        }
    }

    for(int i = 0; i < M; i++){
        ll tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        tmp2--;
        tmp1--;
        cout << AC[tmp2] - AC[tmp1] << endl;
    }
}



