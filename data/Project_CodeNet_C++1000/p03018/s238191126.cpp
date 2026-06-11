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
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

int main(){
    string s;cin>>s;
    s+='z';
    int N=s.size();
    int i=0;ll ans=0;
    while(i<N){
        while(s[i]!='A' && i<N) i++;
        int count=0;
        while(i<N){
            if(s[i]=='A'){
                count++;
                i++;
            }
            else if(s[i]=='B' && s[i+1]=='C'){
                ans+=count;
                i+=2;
            }
            else break;
        }
    }
    cout<<ans<<endl;
    return 0;
}