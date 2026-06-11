#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(int argc, const char * argv[]) {
    int d;
    ll g;
    cin >> d >> g;
    vector<int> p(d, 0);
    vector<int> c(d, 0);
    
    for(int i=0; i<d; i++){
        cin >> p[i] >> c[i];
    }
    
    int ans=1000;
    for(int bit=0; bit<(1 << d); bit++){
        int question=0;
        int order=0;
        ll score=0;
        while(order<d){
            if((bit>>order)&1){
                score += p[order] * 100 * (order+1) + c[order];
                question += p[order];
            }
            order++;
        }
        
        if(score>=g){
            ans =  min(ans, question);
            continue;
        }
        
        order=d-1;
        int count=0;
        while(order>=0){
            if(!(bit>>order&1)){
                score += (order+1)*100;
                question++;
                if(score>=g){
                    ans =  min(ans, question);
                    break;
                }
            }
            count++;
            if(p[order]<count){
                order--;
                count=0;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
