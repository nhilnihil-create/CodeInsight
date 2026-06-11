#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;


int main(){
    LL N,A,B;
    cin >> N >> A >> B;
    vector<int> v;
    if(A+B-1<=N&&N<=A*B){
        if(A==1){
            for(int i=N;i>0;i--){
                cout << i << (i==1?"\n":" ");
            }
            return 0;
        }
        int cnt=N-B;
        int t=N-cnt/(A-1)*A-cnt%(A-1);
        for(int i=1;i<t;i++){
            v.push_back(i);
        }
        for(int i=t+cnt%(A-1);i>=t;i--){
            if(t==0) break;
            v.push_back(i);
        }
        t+=cnt%(A-1);
        for(int i=0;i<cnt/(A-1);i++){
            for(int j=A;j>0;j--){
                v.push_back(t+i*A+j);
            }
        }
        for(int i=N-1;i>=0;i--){
            cout << v[i] << (i==0?"\n":" ");
        }
    }
    else puts("-1");
    return 0;
}