#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    int soinsu[n+1]={};
    for(int i=1;i<=n;i++){
        int I=i;
        for(int j=2;j<=sqrt(I);j++){
            while(I%j==0){
                soinsu[j]++;
                I/=j;
            }
        }
        if(I>1)soinsu[I]++;
    }
    vector<int>prm;
    for(int i=1;i<=n;i++)if(soinsu[i])prm.push_back(soinsu[i]+1);
    int x=0;
    for(int i=0;prm[i]>=75;i++)x++;
    for(int i=0;prm[i]>=15;i++){
        for(int j=0;prm[j]>=5;j++)if(i!=j)x++;
    }
    for(int i=0;prm[i]>=25;i++){
        for(int j=0;prm[j]>=3;j++)if(i!=j)x++;
    }
    for(int i=0;prm[i]>=5;i++){
        for(int j=i+1;prm[j]>=5;j++){
            for(int k=0;prm[k]>=3;k++)if(i!=j && j!=k && k!=i)x++;
        }
    }
    cout<<x<<endl;
    return 0;
}