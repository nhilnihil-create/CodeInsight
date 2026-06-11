#include <iostream>
#include <map>
using namespace std;
long long n,p,cnt;
map<long long, int>v;
int main(){
    cin >> n >> p;
    for(int i = 2; i *1ll* i <= p; i ++)
        while(p % i == 0)
            v[i] ++, p /= i, cnt ++;
    if(p > 1)
        v[p] ++;
    long long res = 1;
    for(map<long long, int> :: iterator it = v.begin(); it != v.end(); it ++)
        for(int i = 0; i < (*it).second / n; i ++)
            res *= it->first;
    cout << res;


}
