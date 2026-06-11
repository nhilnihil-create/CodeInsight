#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    ll k,a,b;
    cin >> k >> a >> b;
    ll now = 1;
    int tmp = k;
    now += min(a-1,k);
    k -= min(a-1,k);
    if(k > 0){
        if(k%2 == 0 && a < b){
            now += (b-a)*k/2;
        }
        else if(k%2 == 1 && a<b){
            k--;
            now += (b-a)*k/2;
            now++;
        }
        else{
            now += k;
        }
        if(now < tmp+1) now = tmp+1;
    }
    
    cout << now << endl;
}