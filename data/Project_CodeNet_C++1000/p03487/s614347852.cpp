#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int N; cin >> N;
    map<long long, int> m{};
    for(int i=0;i<N;i++){
        long long a; cin >> a;
        m[a]++;
    }
    long long ans =0;
    for(auto i=m.begin(); i!=m.end();i++){
        long long a=i->first; long long b=i->second;
        if(b>=a) ans+=b-a;
        else ans+=b;
    }
    cout << ans << endl;
}


