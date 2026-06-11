#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll INF = 1061109567;
const double EPS = 1e-10;

int main(){
    int N;
    cin>>N;
    int C[N],S[N],F[N];
    int time[N];
    for(int i=0;i<N-1;i++){
        cin>>C[i]>>S[i]>>F[i];
        time[i]=0;
    }
  time[N-1]=0;
    for(int i=0;i<N-1;i++){
        time[i]+=S[i]+C[i];
        for(int j=i+1;j<N-1;j++){
            if(time[i]<S[j]){
                time[i]=S[j];
            }
            while(!((time[i]%F[j])==0)){
                time[i]++;
            }
            time[i]+=C[j];
        }
    }

    for(int i=0;i<N;i++){
        cout<<time[i]<<endl;
    }
    return 0;
}