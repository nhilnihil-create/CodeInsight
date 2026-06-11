#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N;
    string S;
    cin>>N>>S;
    long long int cou[28]={0};
    for(int i=0;i<N;i++)cou[S[i]-'a']++;
    long long int ans=1;
    for(int i=0;i<26;i++){
        ans*=(cou[i]+1);
        ans%=1000000007;
    }
    ans--;
    if(ans==-1)ans=1000000006;
    cout<<ans<<endl;
    return 0;
}
