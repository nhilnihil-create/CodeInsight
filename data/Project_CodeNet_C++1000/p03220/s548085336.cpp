#include<iostream>
#include<cmath>
using namespace std;

int N,T,A;
int H[1050];
const int INF=10000000000;
int main(){
    cin>>N;
    cin>>T>>A;

    double res=INF;
    int temp_i;
    for(int i=1;i<=N;++i)cin>>H[i];

        for(int i=1;i<=N;++i){
            double H_med=abs(A-(T-H[i]*0.006));
                if(res>H_med){
                    res=H_med;
                    temp_i=i;
                }
        }
    cout<<temp_i;
}