#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){
   
    int N;cin>>N;
    int j=-1;
    for(int i=1;i<=1000;i++){
        if(i*(i+1)/2==N) j=i;
    }
    
    if(j==-1) cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        cout<<j+1<<endl;
        vector<int> S(j+1,0);
        S[j-1]=1;
        S[j]=1;
        vector<int> T[j+1];
        int now=1;
        
        do{
            for(int i=0;i<j+1;i++){
                if(S[i]) T[i].push_back(now);
            }
            now++;
        }while(next_permutation(all(S)));
        
        for(int i=0;i<j+1;i++){
            cout<<j;
            for(int k=0;k<j;k++){
                cout<<" "<<T[i][k];
            }
            cout<<endl;
        }
    }
}
