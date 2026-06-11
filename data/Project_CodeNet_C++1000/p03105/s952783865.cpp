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
typedef pair<ll,ll > P;
typedef pair<P,ll>Q;

int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<min(b/a,c)<<endl;
    return 0;
}