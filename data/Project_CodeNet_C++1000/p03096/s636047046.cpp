#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const long modulo = 1e9+7;

int main(){
    long long N,Ci,last,i,j;
    while(cin >> N){
        last = 0;
        vector<long> stones;
        for(i = 0; i < N; i++){
            cin >> Ci;
            if(Ci != last) stones.push_back(Ci);
            last = Ci;
        }
        long long ans[stones.size() + 1],store[200007];
        memset(ans,0,sizeof(ans));
        memset(store,0,sizeof(store));
        ans[0] = 1;
        for(i = 1; i <= stones.size(); i++){
            ans[i] = (ans[i - 1] + store[stones[i - 1]]) % modulo;
            store[stones[i - 1]] = ans[i];
        }
        cout << ans[stones.size()] << endl;
    }
    return 0;
}