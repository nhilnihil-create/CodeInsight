#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)
#define REP(i,n) for(long long i(0);(i)<(n);(i)++)
ll INF = 1LL << 60;

void solve(long long N, long long C, std::vector<long long> s, std::vector<long long> t, std::vector<long long> c){
    set< pair<pll, ll> > A;
    REP(i, N){
        A.insert(make_pair(pll(s[i], t[i]), c[i] ));
    }
    ll cnt = 0;
    while(!A.empty()){
        cnt++;
        pair<pll, ll> tmp = *A.begin();
        A.erase(A.begin());
        vector<set< pair<pll, ll> >::iterator > to_erase;
        for(auto it=A.begin(); it != A.end(); it++){
            if(it->second == tmp.second){ //* same channel
                if(it->first.first >= tmp.first.second){ //* can stay on the same machine
                    tmp = *it;
                    to_erase.push_back(it);
                }
            }
            else{ //* different channes
                if(it->first.first >= tmp.first.second+1){ //* can stay on the same machine
                    tmp = *it;
                    to_erase.push_back(it);
                }
            }
        }
        REP(i, to_erase.size()){
            A.erase(to_erase[i]);
        }
    }
    cout << cnt << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long C;
    scanf("%lld",&C);
    std::vector<long long> s(N);
    std::vector<long long> t(N);
    std::vector<long long> c(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&s[i]);
        scanf("%lld",&t[i]);
        scanf("%lld",&c[i]);
    }
    solve(N, C, std::move(s), std::move(t), std::move(c));
    return 0;
}
