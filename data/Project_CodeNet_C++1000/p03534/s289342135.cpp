#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005;

int main(){
    
    string S;cin>>S;
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='a') cnt1++;
        if(S[i]=='b') cnt2++;
        if(S[i]=='c') cnt3++;
    }
    vector<int> T={cnt1,cnt2,cnt3};
    sort(all(T));
    if(T[2]-T[0]==1||T[2]-T[0]==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}
