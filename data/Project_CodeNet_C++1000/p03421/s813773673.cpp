#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <string.h>
#include <string>
#include <set>
#include <memory.h>
#include <functional>
#include <bitset>
using namespace std;
#define ll long long

const int N = 3e5+15;

int ret[N];
void solve() {
    int n,inc,dec;
    cin>>n>>inc>>dec;
    if(inc+dec-1>n || (ll)inc*dec<n) {
        printf("-1\n");
        return;
    }
    bool isSwaped = false;
    if(inc<=dec) {
        isSwaped = true;
        swap(inc,dec);
    }
    
    bool canMake = false;
    if(dec==1) {
        if(inc!=n) {
            printf("-1\n");
            return;
        }
        canMake = true;
        for(int i=0;i<n;++i) {
            ret[i] = i+1;
        }
    } else {
        int pos = 0;
        for(int i=0;i<dec;++i) {
            ret[i] = dec - i;
        }
        int rem = inc-1 + dec;
        rem = n - rem;
        pos = dec;
        if(rem==0) {
            canMake = true;
            for(int i = dec;i<n;++i) {
                ret[i] = i+1;
            }
        } else {
            rem += inc-1;
            pos = dec;
            int r = n;
            while(true) {
                int l = r - (inc-1) + 1;
                bool isEnd = false;
                if(l<=dec) {
                    isEnd = true;
                }
                l = max(l,dec+1);
                
                for(int i=l;i<=r;++i) {
                    ret[pos++] = i;
                }
                r = l-1;
                if(isEnd) {
                    break;
                }
            }
            canMake = true;
        }
    }
    if(isSwaped) {
        for(int i=0;i<n;++i) {
            ret[i] = n - ret[i] + 1;
        }
    }
    for(int i=0;i<n;++i) {
        printf("%d ",ret[i]);
    }
    cout<<endl;
}

int main() {
    //freopen("/Users/gotop/Documents/ps_practice/ps_practice/input.txt", "r", stdin);
    solve();
}
