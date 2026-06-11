#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll>Q;


int main(void){
    string s;
    cin>>s;
    int n = s.length();
    int plus=0,minus=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+')plus++;
        else minus++;
    }
    cout<<plus-minus<<endl;
    return 0;
}