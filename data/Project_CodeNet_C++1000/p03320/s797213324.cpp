#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=301,INF=1<<30;

int main(){
    
    ll K;cin>>K;
    
    if(K==10){
        for(int i=1;i<=9;i++){
            cout<<i<<endl;
        }
        cout<<19<<endl;
    }else{
        vector<ll> A;
        vector<double> B;
        int cnt=27;
        for(int i=1;i<=9;i++){
            cout<<i<<endl;
        }
        for(int i=1;i<=9;i++){
            cout<<i*10+9<<endl;
        }
        for(int i=1;i<=9;i++){
            cout<<i*100+99<<endl;
        }
        for(int keta=1;keta<=12;keta++){
            for(int i=100;i<=999;i++){
                ll a=(i+1)*pow(10,keta)-1;
                double asum=(i/100)+(i%100/10)+(i%10)+(keta)*9;
                A.push_back(a);
                B.push_back(a/asum);
            }
        }
        
        for(int i=0;i<A.size();i++){
            bool ok=true;
            for(int j=i+1;j<A.size();j++){
                if(B[i]>B[j]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                cout<<A[i]<<endl;
                cnt++;
            }
            if(cnt==K) break;
        }
    }
}
