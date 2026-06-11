#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
using namespace std;

int main(){
    int p=pow(10,9)+7;
    string S;cin>>S;
    int N=S.size();

    long long dp_ABC[100010],dp_BC[100010],dp_C[100010];
    int mpow=1; //分岐数

    //初期化
      dp_ABC[0]=dp_BC[0]=dp_C[0]=0;
    //漸化式
    for(int i=1;i<=N;i++){
        if(S[N-i]=='A'){
            dp_ABC[i]=(dp_ABC[i-1]+dp_BC[i-1])%p;
            dp_BC[i]=dp_BC[i-1];
            dp_C[i]=dp_C[i-1];
        }
        if(S[N-i]=='B'){
            dp_ABC[i]=dp_ABC[i-1];
            dp_BC[i]=(dp_BC[i-1]+dp_C[i-1])%p;
            dp_C[i]=dp_C[i-1];
        }
        if(S[N-i]=='C'){
            dp_ABC[i]=dp_ABC[i-1];
            dp_BC[i]=dp_BC[i-1];
            dp_C[i]=(dp_C[i-1]+mpow)%p;
        }
        if(S[N-i]=='?'){
            dp_ABC[i]=(((dp_ABC[i-1]+dp_BC[i-1])%p+dp_ABC[i-1])%p+dp_ABC[i-1])%p;
            dp_BC[i]=(((dp_BC[i-1]+dp_C[i-1])%p+dp_BC[i-1])%p+dp_BC[i-1])%p;
            dp_C[i]=(((dp_C[i-1]+dp_C[i-1])%p+dp_C[i-1]%p)+mpow)%p;
            mpow=((mpow+mpow)%p+mpow)%p;
        }
    }

    cout<<dp_ABC[N]<<endl;
    return 0;
}