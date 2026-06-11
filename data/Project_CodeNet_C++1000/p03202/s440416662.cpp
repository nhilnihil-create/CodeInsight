#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int N;
int nos[200010];
bool possib(int x){
    // Unless otherwise specified all the characters are 0
    map<int,int> curr;
    for(int i=1;i<N;i++) if(nos[i] <= nos[i-1]){
        int idx = nos[i];
        while(idx > 0){
            curr[idx] += 1;
            if(curr[idx] == x){
                curr[idx] = 0;
                idx -= 1;
            }else break;
        }
        if(idx == 0) return false;
        for(auto it = --curr.end();it->first > nos[i];it = --curr.end()) curr.erase(it);
    }
    return true;
}


int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&nos[i]);
    bool inc = true;
    for(int i=1;i<N && inc;i++) if(nos[i] <= nos[i-1]) inc = false;
    if(inc){
        printf("1\n");
        return 0;
    }
    int lo = 2, hi = 3e5;
    while(lo < hi){
        int mid = (lo + hi)>>1;
        if(possib(mid)) hi = mid;
        else lo = mid+1;
    }
    printf("%d\n",hi);
}