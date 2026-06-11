#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

float min(float a, float b){
    if (a<b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> t(N+3,0),v(N+2,0);
    for(int i=2; i<N+2; i++){
        int a;
        cin >> a;
        t[i]=t[i-1]+2*a;
    }
    t[N+2]=t[N+1];
    for(int i=1; i<N+1; i++){
        cin >> v[i];
    }
    v[0]=0;v[N+1]=0;
    vector<float> v_limit(t[N+2]+1,10000);
    v_limit[0]=0;
    v_limit[t[N+2]]=0;
    for(int i=0; i<N+2; i++){
        //cout << i << ' ' << t[i] << ' ' << t[i+1] << ' ' << v[i] << endl;
        for(int j=t[i]; j<=t[i+1]; j++){
            v_limit[j]=min(v_limit[j],v[i]);
        }
        for(int j=1; t[i]-j>=0; j++){
            v_limit[t[i]-j]=min(v_limit[t[i]-j],(float)v[i]+0.5*j);
        }
        for(int j=1; t[i+1]+j<=t[N+2];j++){
            v_limit[t[i+1]+j]=min(v_limit[t[i+1]+j], (float)v[i]+0.5*j);
        }
    }
    float ans=0;
    for(int i=0; i<t[N+2]; i++){
        ans+=(v_limit[i+1]+v_limit[i]);
        if(i%2==0){
            //cout << i/2 << ' ' << v_limit[i] << endl;
        }
    }
    cout << fixed << setprecision(4) << ans/4 << endl;
}