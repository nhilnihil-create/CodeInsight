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
typedef pair<int,int> P;
 
int main(){
    int n;
    string a,b,c;
    cin>>n>>a>>b>>c;
    int ans = 0;
    for(int i=0;i<n;i++){
        set<char>s;
        s.insert(a[i]);
        s.insert(b[i]);
        s.insert(c[i]);
        if(s.size()==3)ans+=2;
        if(s.size()==2)ans+=1;
    }
    cout<<ans<<endl;
}
