#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int main(){
    string S;cin>>S;
    int N=S.size();
    int ans=N;
    for(int i=0;i<N-1;i++){
        if(S[i]!=S[i+1]){
            ans=min(ans,max(i+1,N-i-1));
        }
    }
    cout<<ans<<endl;
    return 0;
}