#define _USE_MATH_DEFINES
# include <bits/stdc++.h>
using namespace std;
int main() {
    long long N,C;
    cin >> N>>C;
    long long x[100000],v[100000];
    long long f[100000],g[100000];
    long long when[100000];
    long long i_made[100000];
    
    long long v_sum=0;
    long long res=0;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> v[i];
        v_sum+=v[i];
        i_made[i]=v_sum;
        f[i]=i_made[i]-x[i];
        if(i>0){
            g[i]=max(g[i-1],f[i]);
        }else{
            g[0]=max(f[i],(long long)0);
        }
        if(g[i]!=f[i]){
            if(i>0){
                when[i]=when[i-1];
            }else{
                when[i]=100001;
            }
        }else{
            when[i]=i;
        }
    }
    
    for (int i = 1; i < N; i++) {
        long long cost;
        long long score;
        cost=(C-x[i])*2;
        score=v_sum-i_made[i-1]+g[i-1];
        res=max(res,score-cost);
    }
    res=max(res,v_sum-(C-x[0]));
    res=max(res,g[N-1]);
    v_sum=0;
    for (int i = 0; i < N; i++) {
        long long r_i=N-1-i;
        v_sum+=v[r_i];
        i_made[i]=v_sum;
        f[i]=i_made[i]-(C-x[r_i]);
        if(i>0){
            g[i]=max(g[i-1],f[i]);
        }else{
            g[0]=max(f[i],(long long)0);
        }
        if(g[i]!=f[i]){
            if(i>0){
                when[i]=when[i-1];
            }else{
                when[i]=100001;
            }
        }else{
            when[i]=i;
        }
    }
    
    for (int i = 1; i < N; i++) {
        long long r_i=N-1-i;
        long long cost;
        long long score;
        cost=x[r_i]*2;
        score=v_sum-i_made[i-1]+g[i-1];
        res=max(res,score-cost);
    }
    res=max(res,v_sum-x[N-1]);
    res=max(res,g[N-1]);
    cout << res<<endl;
    return 0;
}