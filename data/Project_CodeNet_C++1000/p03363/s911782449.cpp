#include <iostream>
#include <map>
using namespace std;

map<long long, long long> mp;

void print(){
    map<long long, long long>::iterator it;
    long long sum=0;
    for(it=mp.begin();it!=mp.end();it++){
        pair<long long, long long> item = *it;
        sum+=item.second*(item.second-1)/2;
    }
    cout << sum << endl;
}

int main(){
    long long n, a, sum=0;
    cin >> n;
    mp[sum]++;
    for(int i=1;i<=n;i++){
        cin >> a;
        sum+=a;
        mp[sum]++;
    }
    print();
    return 0;
}