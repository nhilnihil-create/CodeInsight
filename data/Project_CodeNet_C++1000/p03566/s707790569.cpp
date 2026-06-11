#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main(){
    //縦横2倍する
    int N; cin>>N;
    vector<int> t(N),v(N);
    vector<int> point(N+1,0);
    for (int i = 0; i < N; ++i) {
        cin>>t[i]; t[i]*=2;
        point[i+1]=point[i]+t[i];
    }
    for (int i = 0; i < N; ++i) {
        cin>>v[i]; v[i]*=2;
    }
    vector<vector<int>> limit(N+2,vector<int> (point[N]+1,0));

    //初速0制限
    for(int i=0;i<=point[N];++i){
        limit[0][i]=i;
    }
    //最終0制限
    for(int i=0;i<=point[N];++i){
        limit[N+1][point[N]-i]=i;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <=point[N]; ++j) {
            if(j<point[i]) limit[i+1][j]=v[i]+point[i]-j;
            else if(j>point[i+1]) limit[i+1][j]=v[i]+j-point[i+1];
            else limit[i+1][j]=v[i];
        }
    }

    vector<int> speed(point[N]+1,(int)1e9);
    for (int i = 0; i <=point[N]; ++i) {
        for (int j = 0; j <=N+1; ++j) {
            speed[i]=min(speed[i],limit[j][i]);
        }

    }

    double ans=0.0;
    for(int i=0;i<point[N];++i){
        ans+=(speed[i]+speed[i+1])/2.0;
        //printf("%d : %d\n",i,speed[i]);
    }
    ans/=4;

    printf("%.5f \n",ans);

    return 0;
}

